import numpy as np
import matplotlib.pyplot as plt
from crank_nic import *
from euler_exp import *
from euler_imp import *

u0 = lambda x : np.sin(np.pi * x)
N = 100
M = 100
T = 10

u = crank_nic(T, N, M, u0)
#u = euler_exp(T, N, M, u0)
#u = euler_imp(T, N, M, u0)

x = np.linspace(0,1, M)

plt.plot(x, u[0], label="initial condition")
plt.plot(x, u[10], label="condition at time 1.0s")
plt.plot(x, u[25], label="condition at time 2.5s")
plt.plot(x, u[75], label="condition at time 7.5s")

plt.title("Simulation of the diffusion equation using Crank-Nicholson scheme")
plt.xlabel("x")
plt.legend()
plt.show()
