import numpy as np

def get_fd_stencil(
        diff_order : int,
        x_eval : float,
        x_points : np.ndarray,
):
    """
    Generate finitie difference stencils

    This follows
    "Generation of Finite Difference Formulas on Arbitrarily Spaced Grids"
    by Bengt Fornberg

    diff_order:
        Order of derivative
        
    x_eval:
        Point to approximate the derivative on.
        This is typically a point in x_points, but can be also used for interpolation.
        
    x_points:
        Points to use for evaluating the derivative on
    """
    
    M = diff_order
    N = len(x_points)-1

    delta = np.zeros((M+1, N+1, N+1))
    
    delta[0,0,0] = 1
    c1 = 1
    
    for n in range(1, N+1):
        c2 = 1
        for v in range(0, n):
            c3 = x_points[n] - x_points[v]
            c2 = c2*c3
            
            for m in range(0, min(n, M)+1):
                delta[m,n,v] = ((x_points[n]-x_eval)*delta[m,n-1,v] - m*delta[m-1,n-1,v])/c3
        
        for m in range(0, min(n,M)+1):
            delta[m,n,n] = c1/c2 * (m*delta[m-1,n-1,n-1] - (x_points[n-1] - x_eval) * delta[m,n-1,n-1])
        
        c1 = c2
    
    stencil = delta[M,N,:]
    
    if 1:
        stencil[np.abs(stencil) < np.max(np.abs(stencil))*1e-14] = 0

    return delta[M,N,:] 
