import numpy as np

def nodes(k, N):
    """
    Associate to k a set of nodes (ti) in [0,1].
    We have k values equal to 0 at the beginning then N-k+2 increasing
    different values (a linspace(0,1,N-k+2) and finally k values equal
    to 1.

    Parameters:
        k: int = defines the resolution of the Spline, padding for
            the values (ti).
        N: int = Number of values actually different.

    Returns:
        t : ndarray of size N+k+2 = The nodes of the spline.
    """

    t = np.zeros(N+K+2)
    t[k:N+2] = np.linspace(0,1,N-k+2)
    t[N+2:] = 1

    return t

def DeBoor_Cox(k, D, t):
    """
    Calculate the bicubic spline of the control polygon D at point
    t using DeBoor_Cox algorithm.

    Parameters:
        k : int = resolution of the spline.
        D : ndarray of size (2, N+1) = the control polygon
        t : float = point where we calculate S, supposed in [0,1]

    Returns:
        S : ndarray of size 2 = The position of the spline at
            parameter t.
    """

    N = D.shape[1] - 1
    # Creating the Nodes :
    t = nodes(k, N)

    r = 0
    while t[r] > t :
        r += 1

    DBx = np.diag(D[0])
    DBy = np.diag(D[1])
    DB = np.zeros((k+1, k+1, 2))


    for j in range(1,k+1):
        for i in range(r-k+j, r+1):

