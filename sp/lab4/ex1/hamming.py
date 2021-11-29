import numpy as np
import matplotlib.pyplot as plt

def hamming_win(x, N):
        return .54 - .46 * np.cos(2 * np.pi * x/N)

N = 50

n = np. arange(N)
H = hamming_win(n, N)

plt.stem(H)
plt.suptitle("Hamming window", fontsize=16)

plt.show()
