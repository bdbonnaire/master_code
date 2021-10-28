import numpy as np
import matplotlib.pyplot as plt

definition=100
# definition of the plot (ie number of elements where function are evaluated)
x = np.linspace(0,1, definition)

# Boundary Conditions, a corresponds to alpha and b to beta in the worksheet.
a = [1, 10, 0.5]
b = [2,4,7]

###################################### Exact Solution #################################################
diri_exact = lambda x, a, b : -x + (b-a+1)*np.log(1+x)/np.log(2) + a
mixed_exact = lambda x, a, b : -x + 2*(b+1)*np.log(1+x) + a

fig, (ax1, ax2) = plt.subplots(1,2)

ax1.set_title("Solution with Dirichlet conditions")
ax2.set_title("Solution with Mixed conditions")

for i in range(len(a)):
    ax1.plot(x, diri_exact(x, a[i], b[i]), label=r"with $\alpha$=" + str(a[i]) + r" and $\beta=$" + str(b[i]))
    ax2.plot(x, mixed_exact(x, a[i], b[i]), label=r"with $\alpha$=" + str(a[i]) + r" and $\beta=$" + str(b[i]))

#################################### FD Implementation ################################################

#-------------------------------------- Dirichlet BC -----------------------------------#


def diriBC_FD(X, a, b):
    """
    Returns an approximation of the solution using finite difference. The equation is 
        -((1+x)u')' = 1 with Dirichlet boundary condition where u(0)=a, u(1)=b.

        Parameters:
            X (ndarray):    The subdivision of [0,1] used to approximate the solution. The 
                subdivision is supposed regular of step h.
            a (float):      The value of u at 0.
            b (float):      The value of u at 1.

        Returns:
            U (ndarray):    an approximation of u at each point of X. Same size as X.
    """

#____ Matrix implementation ____#

    N=len(X)-1
    h = 1/N

# left hand side of the equation :
    Matrix_diri_LH = np.zeros((N+1,N+1))

## first and last line
    Matrix_diri_LH[0,0] = 1
    Matrix_diri_LH[N,N] = 1

## other lines : 
    for i in range(1,N):
        Matrix_diri_LH[i,i-1] = - h +2*(1 + X[i])
        Matrix_diri_LH[i,i] = -4*(1 + X[i])
        Matrix_diri_LH[i,i+1] = h + 2*(1 + X[i])

# right hand side of the equation :
    Matrix_diri_RH = np.zeros(N+1)

## other lines :
    Matrix_diri_RH.fill(-2*h**2)

## first and last line :
    Matrix_diri_RH[0] = a
    Matrix_diri_RH[N] = b

#________ Solving the system _______#

    U = np.linalg.solve(Matrix_diri_LH,Matrix_diri_RH)

    return U

#subdivision of [0,1]
N_subdiv = 4
X=np.linspace(0,1,N_subdiv+1)

# calculation of the approximate solution
U0 = diriBC_FD(X,a[0],b[0])
U1 = diriBC_FD(X,a[1],b[1])
U2 = diriBC_FD(X,a[2],b[2])
ax1.plot(X,U0, 'r-', label="approximate solution",)
ax1.plot(X,U1, 'r-',)
ax1.plot(X,U2, 'r-',)
ax1.legend()

plt.legend()

#-------------------------------------- Mixed BC -----------------------------------#


def MixedBC_FD(X, a, b):
    """
    Returns an approximation of the solution using finite difference. The equation is 
        -((1+x)u')' = 1 with Mixed boundary condition where u(0)=a, u'(1)=b.

        Parameters:
            X (ndarray):    The subdivision of [0,1] used to approximate the solution. The 
                subdivision is supposed regular of step h.
            a (float):      The value of u at 0.
            b (float):      The value of u' at 1.

        Returns:
            U (ndarray):    an approximation of u at each point of X. Same size as X.
    """

#____ Matrix implementation ____#

    N=len(X)-1
    h = 1/N

# left hand side of the equation :
    L = np.zeros((N+1,N+1))

## first and last line
## Application of the BC
    L[0,0] = 1
    L[N,N-2] = 1
    L[N,N-1] = -4
    L[N,N] = 3


## other lines : 
    for i in range(1,N):
        L[i,i-1] = - h +2*(1 + X[i])
        L[i,i] = -4*(1 + X[i])
        L[i,i+1] = h + 2*(1 + X[i])

# right hand side of the equation :
    R = np.zeros(N+1)

## other lines :
    R.fill(-2*h**2)

## first and last line :
    R[0] = a
    R[N] = b*2*h

#________ Solving the system _______#

    U = np.linalg.solve(L,R)

    return U

# calculation of the approximate solution
U0 = MixedBC_FD(X,a[0],b[0])
U1 = MixedBC_FD(X,a[1],b[1])
U2 = MixedBC_FD(X,a[2],b[2])
ax2.plot(X,U0, 'r-', label="approximate solution",)
ax2.plot(X,U1, 'r-',)
ax2.plot(X,U2, 'r-',)
ax2.legend()

plt.legend()
fig.show()

#________ Computing the error _______#

figErr, (axErr1, axErr2) = plt.subplots(1,2)

def error_calculation(exact, approx):
    """ 
    Returns the error between the exact and approximated solution using the infinity norm.
        (ie. the max of the absolute difference of each element of the array)
    """
    return np.linalg.norm(approx - exact, np.inf)
    #return np.amax(np.abs(exact - approx)) 

def error_array_diri(N):
    """
    calculates the error between the exact and approximated solution with Dirichlet boundary conditions
    when the subdivision of [0,1] has N points.
    """

    subdiv = np.linspace(0,1, N);
    # We take a particular Dirichlet BC but it should not matter much in the calculation of the error.
    approx = diriBC_FD(subdiv, a[0], b[0])
    return error_calculation(diri_exact(subdiv, a[0], b[0]), approx)

def error_array_mixed(N):
    """
    calculates the error between the exact and approximated solution with Mixed boundary conditions
    when the subdivision of [0,1] has N points.
    """

    subdiv = np.linspace(0,1, N);
    # We take a particular Dirichlet BC but it should not matter much in the calculation of the error.
    approx = MixedBC_FD(subdiv, a[0], b[0])
    return error_calculation(mixed_exact(subdiv, a[0], b[0]), approx)

Nvalues = np.arange(5, 100, 1, dtype=int)
error_diri = np.array([ error_array_diri(n) for n in Nvalues ])
error_mixed = np.array([ error_array_mixed(n) for n in Nvalues ])

x = np.linspace(1/50,1/25,4)
axErr1.loglog((1/Nvalues), error_diri)
axErr1.plot(x, x**2, label=r"$h^2$ reference slope")
axErr1.plot(x, x, label=r"$h$ reference slope")

axErr1.legend()
axErr2.loglog((1/Nvalues), error_mixed,)
axErr2.plot(x, x**2, label=r"$h^2$ reference slope")
axErr2.plot(x, x, label=r"$h$ reference slope")

figErr.suptitle(r"$||\cdot||_\infty$ error for the Dirichlet and mixed BC")
figErr.show() 
figErr.savefig("error")
