import numpy as np

def euler_imp(T, N, M, u0):
    """
    Approximates, using Euler 2nd order implicit in space scheme,
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

    u = np.zeros((N, M))
    u[0] = u0(x)

    # definition of a constant to make things more readable
    l = v * dt / (dx**2)

    # introducing matrices to solve the linear equations
    A = np.zeros((M,M))
    A[0,0] = 1
    A[M,M] = 1

    for j in np.arange(1, M-1):
        A[j, j-1] = -l
        A[j, j] = 2*l+1
        A[j, j+1] = -l

    for n in np.arange(1, N):
        u[n+1] = np.linalg.solve(A, u[n])

    return u
