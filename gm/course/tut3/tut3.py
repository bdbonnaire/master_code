import numpy as np
import matplotlib.pyplot as plt

#----------------------
# discrete derivature
def derivative(t,f):
    deriv_f = np.zeros(f.shape)
    
    #calculates the discrete derivative for all the elements except the last
    for i in range(len(t)-1):
        deriv_f[:,i] = (f[:,i]-f[:,i+1])/(t[i]-t[i+1])

    # last element to avoid errors with the array overflow
    deriv_f[:,len(t)-1] = (f[:,len(t)-2]-f[:,len(t)-1])/(t[len(t)-2]-t[len(t)-1])
    
    return deriv_f

def normal_vector(t,f):
    n = len(t)
    tangent_f = np.zeros((3,n))
    df = derivative(t,f)

    #Calculation of the tangent vector
    for i in range(n) :
        tangent_f[:,i] = df[:,i] / np.linalg.norm(df[:,i],2)
    normal_f = derivative(t, tangent_f)

    # Calculation of the normal vector
    for i in range(n) :
        if np.linalg.norm(normal_f[:,i], 2) :
            normal_f[:,i] = normal_f[:,i] / np.linalg.norm(normal_f[:,i], 2)

    return normal_f # normal_f is of size 3 x n

def curvature(t, f):

    n = len(t)
    # calculating the derivatives
    d1_f = derivative(t,f)
    d2_f = derivative(t,d1_f)

    # wedge product norm 
    wedge = np.array( [ np.linalg.norm( np.cross(d1_f[:,i], d2_f[:,i]), ord=2 ) for i in range(n) ] )

    # norm of the first derivative cubed
    norm_d1_f_cubed = np.linalg.norm(d1_f, ord=2, axis=1)**3

    curvature_f = wedge / norm_d1_f_cubed

    return curvature_f

def evolute(t,f):
    normal_f = normal_vector(t, f)
    k_f = curvature(t, f)

    evolute_f = f + k_f**(-1) * normal_f
    
    return evolute_f
