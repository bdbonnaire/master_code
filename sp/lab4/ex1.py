import numpy as np
import matplotlib.pyplot as plt

#number of frequency bins
L = 1024

fig, axes = fig.subplots(1,3)

def hamming_win(x, N):
        return .54 - .46 * np.cos(2 * np.pi * x/N)
N=100
n = np.arange(0, N)
rect = np.ones(N)
print(rect)
rect_norm = rect / np.linalg.norm(rect, ord=1)
print(rect_norm)

hamming = hamming_win(n, N)
hamming_norm = hamming / np.linalg.norm(hamming, ord=1)

hamming_fft = np.fft.fft(hamming_norm, n=L)
hamming_fft = np.fft.fftshift(hamming_fft)
rect_fft = np.fft.fft(rect_norm, n=L)
rect_fft = np.fft.fftshift(rect_fft)

plt.plot(np.arange(-L/2, L/2), np.abs(rect_fft), label="rectangle window")
plt.plot(np.arange(-L/2, L/2), np.abs(hamming_fft), label="Hamming window")
plt.legend()
plt.show(block=False)
