import numpy as np

def crank_nic(T, N, M, u0):
    """
    Approximates, using Crank-Nicolson scheme,
    the solution to the 1D diffusion equation. 
    dt u - 1/pi² d²x u = 0
    with x in [0,1], t in [0, T] and u0 the initial time
    condition (ie u(x, 0)).

    Parameters:
        T: float = The time window, for how long the approximation runs ?
        N: int = number of steps in time.
        M: int = number of steps in space.
        u0: function = initial time condition

    returns:
        u: NxM ndarray = approximation of the solution. The first axis gives
            time, the second space.
    """
    v = 1/ (np.pi**2)

    # spacings
    dt = T / N
    dx = 1 / M

    t = np.linspace(0, T, N)
    x = np.linspace(0, 1, M)

    u = np.zeros((N, M), dtype=float)
    u[0] = u0(x)

    # definition of a constant to make things more readable
    l = v * dt / (2*dx**2)

    # introducing matrices to solve the linear equations
    A = np.zeros((M,M))
    A[0,0] = 1
    A[M-1,M-1] = 1

    for j in np.arange(1, M-1):
        A[j, j-1] = -l
        A[j, j] = 2*l+1
        A[j, j+1] = -l

    B = np.zeros(M)

    for n in np.arange(0, N-1):
        # definition of the second part of the equation
        for i in np.arange(1, M-1):
            B[i] = l*u[n, i-1] + (1-2*l)*u[n,i] + l*u[n, i+1]

        u[n+1] = np.linalg.solve(A, B)

    return u
