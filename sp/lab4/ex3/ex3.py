import numpy as np
import matplotlib.pyplot as plt
import numpy.fft as fft

def finite_impulse_response(f0, N):
    """
    Calculates the finite impulse response with the hamming window.
    Parameters:
        f0 : float = cutoff frequency
        N : int = number of coefficients to keep. N is supposed even

    Returns :
        g : ndarray = fourier coefficients of the finite impulse response.
    """
    hn_tilda = lambda n, f0 : 2*f0*np.sinc(2*f0*(n-1/2))

    n = np.arange(-N//2, N//2)
    h = hn_tilda(n, f0)

    w_h = lambda n : .54 - .46 * np.cos(2 * np.pi * n/N) 

    n = np.arange(0, N)
    g = h * w_h(n)

    return g

f0 = 1/8
f1 = 1/4
g = finite_impulse_response(f0, 50)
n = np.arange(-25, 25)
h = 2 * g * np.cos(2*np.pi*f1*n)

H = fft.fft(h, 1024)
H = fft.fftshift(H)

N = np.arange(-1024//2, 1024//2) / 1024

plt.axvline(f1 + f0)
plt.axvline(-(f1 + f0))
plt.axvline(f0)
plt.axvline(-f0)
plt.plot(N, np.abs(H))
plt.show()
