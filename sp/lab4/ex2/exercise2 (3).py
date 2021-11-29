from numpy import *
import matplotlib.pyplot as plt
from numpy.fft import fft, fftshift

#Hamming window
def w_h(k, N):
    #Hamming window
    if int(k) in range(N):
        return 0.54 - 0.46 * cos(2 * pi * k / N)
    else:
        return 0

#discretization of Hamming window
def Hamming_window(N):
    n = arange(0, N)
    wh = []
    for elem in n:
        wh.append(w_h(elem, N))
    return wh

#analytic value of hn
def true_hn(f_0, n):
    return 2*f_0 * sinc(f_0*n)

#analytic value of hn_tilde
def compute_hn_tilde(f_0, n):
    return 2*f_0 * sinc(f_0*(2*n-1))

#computation of signal g
def FIR(f_0, N):
    if N%2 == 1:
        n = arange(-(N-1)//2, (N-1)//2 + 1)
    else:
        n = arange(-N// 2, N//2)

    hn = compute_hn_tilde(f_0, n)
    wh = Hamming_window(N)
    g = hn * wh

    return hn,g

if __name__ == "__main__":

    #definition of test values for f_0 and N
    all_f_0 = [1/8, 1/4]
    all_N = [11, 20]
    for j in range(len(all_f_0)):
        for i in range(len(all_N)):

            #computation of hn and g
            f_0 = all_f_0[j]
            N = all_N[i]
            hn, g = FIR(f_0, N)

            #definition of frequency bins and frequency locations
            L = 1024
            k = linspace(-L/2, L/2-1, L)

            #computations of fourier transforms of both signals
            fft_hn = fftshift(fft(hn, L))
            fft_g = fftshift(fft(g, L))

            #plotting
            fig = plt.figure(i+j*2)
            plt.plot(k/L, abs(fft_hn), color="blue", label="$h$")
            plt.plot(k/L, abs(fft_g), color="red", label="$g$")
            plt.plot([-f_0, -f_0], [-0.1, 0.6], linestyle="--", color="grey", label="±f_0")
            plt.plot([f_0, f_0], [-0.1, 0.6], linestyle="--", color="grey")

            plt.title("Modulus of Fourier transforms of signals $h$ and $g$ for N = "+str(N))
            plt.legend()
            fig.savefig("plotexo2_" + str(i+j*2) + ".pdf")
    plt.show()

