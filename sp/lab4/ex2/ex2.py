import numpy as np
import numpy.fft as fft
import matplotlib.pyplot as plt

def finite_impulse_response(f0, N):
    """
    Compute the finite impulse response for a signal of size N.
    Cut-off at frequency f0, supposed < 1/2.
    TODO : make different version depending on the parity of N
    """
    #coefficients h_n tilda computed theoretically of the truncated
    # filter
    hn_tilda = lambda n : 2 * f0 * np.sinc(2 * np.pi * f0 * (n-1/2))

    #Hamming window coefficients
    w_h = lambda n : .54 - .46 * np.cos(2 * np.pi * n/N) 

    n = np.arange(-N//2, N//2 -1)
    #Calculates the coefficients such that f_h[0] = hn_tilda[-N/2].
    #   thus needs shifting before ifft
    f_h = hn_tilda(n)
    #shifting
    f_h = fft.fftshift(f_h)
    
    h = fft.ifft(f_h)

    # Creation of the Hamming window
    n = np.arange(N-1)
    W = w_h(n)

    # calculating the response using Hamming window
    g = h*W

    return g

N=200
g = finite_impulse_response(1/4, N)
f_g = fft.fft(g)
f_g = fft.fftshift(f_g)

hn_tilda = lambda n, f0 : 2*f0*np.sinc(2*np.pi*f0*(n-1/2))
n = np.arange(-N//2, N//2)
k = np.arange(N)
H = hn_tilda(n, 1/4)
S = np.exp(2j*np.pi*1/2*k)*fft.fft(H)
S = fft.fftshift(S)

#plt.plot(n,f_g)
plt.plot(n, np.abs(S))
plt.show();
