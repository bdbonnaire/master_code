import numpy as np
import numpy.fft as fft
import matplotlib.pyplot as plt

# the coefficients of h when N is even
hn_tilda = lambda n, f0 : 2*f0*np.sinc(2*f0*(n-1/2))

# number of frequency bins
L = 1024

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
    S = fft.fft(H, L)
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
    hn_tilda = lambda n, f0 : 2*f0*np.sinc(2*f0*(n-1/2))

    n = np.arange(-N//2, N//2)
    h = hn_tilda(n, f0)

    w_h = lambda n : .54 - .46 * np.cos(2 * np.pi * n/N) 

    n = np.arange(0, N)
    g = h * w_h(n)

    return g

################ Plotting #############################
fig, axes = plt.subplots(1, 3)
fig.suptitle("Comparison between rectangular and Hamming window with $N$ coefficients", fontsize=16)
N=[10, 100, 200]
f0 = 1/4
for k in N:
    g = finite_impulse_response(f0, k)
    f_g = fft.fft(g, L)
    f_g = fft.fftshift(f_g)

    S = f_h(f0, k)
    n = np.arange(-L//2, L//2) / L

    axes[N.index(k)].set_title(r"$N = $" + str(k))
    axes[N.index(k)].plot(n,abs(f_g), label="Hamming window")
    axes[N.index(k)].plot(n, abs(S), label="rectangular window")
    axes[N.index(k)].axvline(-f0, color='C7', ls='--')
    axes[N.index(k)].axvline(f0, color='C7', ls='--', label=r"$\pm f_0$")

axes[1].set_xlabel("frequencies")
axes[0].set_ylabel("Magnitude")
plt.legend();
plt.show();
