import numpy as np
import numpy.fft as fft
import matplotlib.pyplot as plt

#def finite_impulse_response(f0, N):
#    """
#    Compute the finite impulse response for a signal of size N.
#    Cut-off at frequency f0, supposed < 1/2.
#    TODO : make different version depending on the parity of N
#    """
#    #coefficients h_n tilda computed theoretically of the truncated
#    # filter
#    hn_tilda = lambda n : 2 * f0 * np.sinc(2 * np.pi * f0 * (n-1/2))
#
#    #Hamming window coefficients
#    w_h = lambda n : .54 - .46 * np.cos(2 * np.pi * n/N) 
#
#    n = np.arange(-N//2, N//2 -1)
#    #Calculates the coefficients such that f_h[0] = hn_tilda[-N/2].
#    #   thus needs shifting before ifft
#    f_h = hn_tilda(n)
#    #shifting
#    f_h = fft.fftshift(f_h)
#    
#    h = fft.ifft(f_h)
#
#    # Creation of the Hamming window
#    n = np.arange(N-1)
#    W = w_h(n)
#
#    # calculating the response using Hamming window
#    g = h*W
#
#    return g

def f_h(f0, N):
    """
    Calculates the fourier transform of the filter h. 
    Parameters:
        f0 : float = cutoff frequency
        N : int = number of coefficients to keep 

    Returns:
        S : complex ndarray = the shifted fourier transform of h
    """
        
    hn_tilda = lambda n, f0 : 2*f0*np.sinc(2*np.pi*f0*(n-1/2))
    n = np.arange(-N//2, N//2)
    k = np.arange(N)
    H = hn_tilda(n, 1/4)
    S = np.exp(2j*np.pi*1/2*k)*fft.fft(H)
    S = fft.fftshift(S)
    
    return S

def finite_impulse_response(f0, N):
    h = f_h(f0, N)
    h = fft.fftshift(h)
    h = fft.ifft(h)

    w_h = lambda n : .54 - .46 * np.cos(2 * np.pi * n/N) 

    n = np.arange(0, N)
    g = h * w_h(n)

    return g

N=200
g = finite_impulse_response(1/4, N)
f_g = fft.fft(g)
f_g = fft.fftshift(f_g)

S = f_h(1/4, N)
n = np.arange(-N//2, N//2)

plt.plot(n,abs(f_g))
plt.plot(n, abs(S))
plt.show();
