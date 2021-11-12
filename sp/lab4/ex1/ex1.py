import numpy as np
import matplotlib.pyplot as plt

#number of frequency bins
L = 1024
#sizes of signals
N = [10, 100, 200]

fig, axes = plt.subplots(1,3)
fig.suptitle("Comparison between Hamming window and rectangle window for a signal of size $N$", fontsize=16)

def hamming_win(x, N):
        return .54 - .46 * np.cos(2 * np.pi * x/N)

def plot_Hamming_rect_fft(N, ax):

    n = np.arange(0, N)
    #creation of the rectangular window
    rect = np.ones(N)
    #Normalisation with norm l1
    rect_norm = rect / np.linalg.norm(rect, ord=1)

    #creation of the Hamming window
    hamming = hamming_win(n, N)
    # Normalisation with norm l1
    hamming_norm = hamming / np.linalg.norm(hamming, ord=1)

    # Calculating the fft and shifting it
    # d=L tells the fft to pad the signal with 0 so that L values are returned
    hamming_fft = np.fft.fft(hamming_norm, n=L)
    hamming_fft = np.fft.fftshift(hamming_fft)

    rect_fft = np.fft.fft(rect_norm, n=L)
    rect_fft = np.fft.fftshift(rect_fft)

    # Plotting the modulus of the fourier transforms
    ax.plot(np.arange(-L/2, L/2), np.abs(rect_fft), label="rectangle window")
    ax.plot(np.arange(-L/2, L/2), np.abs(hamming_fft), label="Hamming window")
    ax.set_title(r"Comparison when $N = $" + str(N))
    ax.set_xlabel("Frequency bins")
    ax.set_ylabel("Normalized Magnitude")


plot_Hamming_rect_fft(N[0], axes[0])
plot_Hamming_rect_fft(N[1], axes[1])
plot_Hamming_rect_fft(N[2], axes[2])
plt.legend()

plt.show(block=False)
