import numpy as np

def euler_exp(T, N, M, u0):
    """
    Approximates, using Euler 2nd order explicit in space scheme,
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
            time the second space.
    """
    v = 1/ (np.pi**2)

    # spacings
    dt = T / N
    dx = 1 / M
    print(dt/(dx**2))

    t = np.linspace(0, T, N)
    x = np.linspace(0, 1, M)

    u = np.zeros((N, M))
    u[0] = u0(x)

    for n in np.arange(0, N-1):
        for j in np.arange(1, M-1): 
            u[n+1, j] = u[n, j] + v * dt * ( u[n, j+1] - 2*u[n, j] + u[n, j-1] ) / (dx**2)

    return u
