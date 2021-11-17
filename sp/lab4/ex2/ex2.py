import numpy as np
import numpy.fft as fft
import matplotlib.pyplot as plt

# the coefficients of h when N is even
hn_tilda = lambda n, f0 : 2*f0*np.sinc(2*np.pi*f0*(n-1/2))

def f_h(f0, N):
    """
    Calculates the fourier transform of the filter h. 
    Parameters:
        f0 : float = cutoff frequency
        N : int = number of coefficients to keep 

    Returns:
        S : complex ndarray = the shifted fourier transform of h
    """
        
    n = np.arange(-N//2, N//2)
    H = hn_tilda(n, f0)
    S = fft.fft(H, 1024)
    S = fft.fftshift(S)
    
    return S

def finite_impulse_response(f0, N):
    """
    Calculates the finite impulse response with the hamming window.
    Parameters:
        f0 : float = cutoff frequency
        N : int = number of coefficients to keep. N is supposed even

    Returns :
        g : ndarray = fourier coefficients of the finite impulse response.
    """
    n = np.arange(-N//2, N//2)
    h = hn_tilda(n, f0)

    w_h = lambda n : .54 - .46 * np.cos(2 * np.pi * n/N) 

    n = np.arange(0, N)
    g = h * w_h(n)

    return g

N=100
f0 = 1/4
g = finite_impulse_response(f0, N)
f_g = fft.fft(g, 1024)
f_g = fft.fftshift(f_g)

S = f_h(f0, N)
n = np.arange(-1024//2, 1024//2) / 1024

plt.plot(n,abs(f_g))
plt.plot(n, abs(S))
plt.show();
