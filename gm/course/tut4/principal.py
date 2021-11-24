import numpy as np

def first_form(f, m0, h):
    """
    Returns the first form of the surface parametrized by f at point
    m0. 

    Arguments:
        f: function (float, float) -> (float,float,float) = the C2 
            R2 -> R3 parametrization of the surface.
        m0: ndarray of shape (2) = the point where we calculate the
            first form.
        h : float =  Spacing between values.

    Returns:
        Im_0 : The first form matrix at point m0
    """

    # Calculation of the derivatives at point m0 with 2nd order
    # centered scheme
    dx_f = (f(m0 + [h, 0]) - f(m0 - [h, 0])) / (2*h)
    dy_f = (f(m0 + [0, h]) - f(m0 - [0, h])) / (2*h)
    
    # Calculation of the elements of the matrix
    E = np.linalg.norm(dx_f, ord=2, axis=0)
    F = np.dot(dx_f, dy_f)
    G = np.linalg(dy_f, ord=2, axis=0)

    Im_0 = np.array([E, F], [F, G])
    
    return Im_0

def second_form(f, m0, h):
    """
    Returns the second form of the surface parametrized by f at point
    m0. 

    Arguments:
        f: function (float, float) -> (float,float,float) = the C2 
            R2 -> R3 parametrization of the surface.
        m0: ndarray of shape (2) = the point where we calculate the
            second form.
        h : float =  Spacing between values.

    Returns:
        IIm_0 : The second form matrix at point m0.
    """

    # Calculation of the derivatives at point m0 with 2nd order
    #   centered scheme
    dx_f = (f(m0 + [h, 0]) - f(m0 - [h, 0])) / (2*h)
    dy_f = (f(m0 + [0, h]) - f(m0 - [0, h])) / (2*h)

    # Calculating the gradient in such a way that Df(m0) is at pt 99
    #   of the array
    X = np.linspace(m0 - 100*h, m0 + 100*h, 200)
    diffx_f, diffy_f = gradient(f(X))
    diffxy_f, = gradient(diffy_f)
    dxy_f = diffxy_f[99]

    # Calculation of second derivative using 2nd order centered scheme
    d2x_f = (f(m0 + [h, 0]) + f(m0 - [h, 0]) - 2 * f(m0)) / (h**2)
    d2y_f = (f(m0 + [0, h]) + f(m0 - [0, h]) - 2 * f(m0)) / (h**2)

    # Elements of the second form matrix
    K = np.cross(dx_f, dy_f)
    K = K / np.linalg.norm(K, ord=2)

    L = np.dot(d2x_f, K)
    M = np.dot(d2xy_f, K)
    N = np.dot(d2y_f, K)

    IIm_0 = np.array([[L, M],
                      [M, N]])

    return IIm_0

def principal(f, x0, y0, h=0.001):
    """
    Gives the principal directions and curvatures of the parametrized
    surface f at point (x0, y0).

    Parameters:
        f : function (f,f) -> (f,f,f) = parametrization of the surface
            supposed C2 regular.
        x0, y0 : point where the calculation is done.
        h : float = spacing in the gridpoints for finite difference

    Returns:
       directions : ndarray = directions of the surface 
       curvatures : ndarray = curvatures vectors of the surface

    """
    m0 = np.array([x0,y0])

    Im_0 = first_form(f, m0, h)
    IIm_0 = second_form(f, m0, h)

    inv_Im_0 = np.linalg.inv(Im_0)
    I = np.identity(2)

    Am_0 = inv_Im_0 @ I @ Im_0
    curvature, directions = np.linalg.eig(Am_0)

    return directions, curvatures
