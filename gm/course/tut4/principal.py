import numpy as np

def first_form(f, p):
    dx_f, dy_f= np.grad(f)
    
    E = np.linalg.norm(dx_f[p], ord=2, axis=0)
    F = np.dot(dx_f[p], dy_f[p])
    G = np.linalg(dy_f[p], ord=2, axis=0)

    form = np.array([E, F], [F, G])
    
    return form

def second_form(f, p):

    dx_f, dy_f = np.grad(f)
    L = np.dot(dx_f[p], dy_f[p])

