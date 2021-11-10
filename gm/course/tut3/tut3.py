import numpy as np

def derivative(t,f):
    deriv_f = np.zeros(f.shape)
    n = len(t)
    
    h = t[0] - t[1]
    
    #calculates the discrete derivative for 
    for i in range(n-1):
        deriv_f[:,i] = (f[:,i]-f[:,i+1]) / h
    # last 
    deriv_f[:,n-1] = (f[:, n-3] - 4*f[:,n-2]+3*f[:,n-1]) / (2*(-h))
    
    return deriv_f

def normal_vector(t,f):
    n = len(t)
    
    tangent_f = np.zeros(f.shape)
    df = derivative(t,f)
    for i in range(n) :
        tangent_f[:,i] = df[:,i] / np.linalg.norm(df[:,i],2)
    normal_f = derivative(t, tangent_f)
    
    for i in range(n) :
        if np.linalg.norm(normal_f[:,i], 2) :
            normal_f[:,i] = normal_f[:,i] / np.linalg.norm(normal_f[:,i], 2)
            
    return normal_f # normal_f is of size 3 x n

def curvature(t, f):

    n = len(t)
    # calculating the derivatives
    d1_f = derivative(t,f)
    d2_f = derivative(t,d1_f)
    
    wedge = np.cross(d1_f.T, d2_f.T).T
    
    # wedge product norm 
    wedge_norm = np.linalg.norm( wedge, ord=2, axis=0)

    # norm of the first derivative cubed
    norm_d1_f_cubed = np.linalg.norm(d1_f, ord=2, axis=0)**3

    if f.shape[0] == 3 :
        curvature_f = wedge_norm / norm_d1_f_cubed
    elif f.shape[0] == 2:
        curvature_f = wedge / norm_d1_f_cubed
        
    return curvature_f


def evolute(t,f):
    normal_f = normal_vector(t, f)
    k_f = curvature(t, f)

    evolute_f = f + (1/k_f) * normal_f
    
    return evolute_f
