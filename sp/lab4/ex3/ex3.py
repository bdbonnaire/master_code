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
    if N // 2 == 0 :
        hn_tilda = lambda n, f0 : 2*f0*np.sinc(2*f0*(n-1/2))
        n = np.arange(-N//2, N//2)
    else:
        hn_tilda = lambda n, f0 : 2*f0*np.sinc(2*f0*n)
        n = np.arange(-(N-1)//2, (N+1)//2)

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

########################### Plotting #####################################
# vertical lines
plt.axvline(f1 + f0, linestyle ='--', color='C7')
plt.axvline(-(f1 + f0), linestyle ='--', color='C7')
plt.axvline(f0, linestyle ='--', color='C7')
plt.axvline(-f0, linestyle ='--', color='C7', label =r"$\pm f_0 and \pm f_0 + f_1$")

#bandpass filter
plt.plot(N, np.abs(H), label="Band-pass filter")
plt.suptitle("Band-pass filter using Hamming Window", fontsize=16)
plt.title(r"50 coefficients kept, $f_0 = \frac{1}{8}$ and $f_1 = \frac{1}{4}$")
plt.xlabel("frequency")
plt.ylabel("Magnitude")
plt.legend()
plt.show()
