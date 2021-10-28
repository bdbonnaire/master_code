import numpy as np
import matplotlib.pyplot as plt
import math

################################# Bezier Curve #################################
#----------------------
# Binomial coefficient
def nchoosek(n,p):
    """
    returns the number of partition of cardinal p in a set of card n
    """
    cnp = math.factorial(n) / (math.factorial(p) * math.factorial(n-p))
    return cnp

#---------------------
# Bernstein Polynomials
# N is the degree
# t = np.linspace(0,1,500)
def Bernstein(N,t):
    """
    returns a matrix of size N+1xlen(t) where each element (i,j) gives
    the expression of the i_th Bernstein at point j in t
    """
    BNt = np.zeros((N+1, len(t)))
    for i in range(N+1):
        BNt[i]= nchoosek(N,i) * t**i * (1-t)**(N-i)
    return BNt

def PlotBezierCurve(Polygon):
    """
    plot the bezier Curve given a control polygon

        Polygon : ndarray of size 2xN where the first row
            gives the x_coordinate and the 2nd the y
    """

    t = np.linspace(0,1,200)
    """  creation of the bernstein polynomials for the number of points in
            the control polygon """
    B = Bernstein(len(Polygon[0])-1, t)
    # application to the x value
    Bx = np.array([B[i,:] * Polygon[0][i] for i in range(len(Polygon[0])) ])
    #application to the y value
    By = np.array([B[i,:] * Polygon[1][i] for i in range(len(Polygon[0])) ])

    X = np.sum(Bx, axis=0)
    Y = np.sum(By, axis=0)

    ax.plot(X,Y, 'b-', label="Bezier Curve")
    plt.draw()

################# DeCasteljau ######################

def dif(points, t):
# points is an np array containing the current control polygon
# dif returns an np array of Y(t) where
# [0,1] --> R²
# Y(t) = t*Ai + (1-t)*Ai+1
    return np.array([((1-t)*points[i] + t*points[i+1]) for i in range(len(points)-1)])

# returns the n_th Descasteljau polygon for a certain 
def deCasteljau_nth(control, n:int, t):
    """
    returns the n_th Decasteljau polygon tied to the control polygon
    """
    P = control
    for i in range(n):
        P=dif(P,t)

    return P

def DeCasteljau(Polygon,t):#returns the two diagonals
    """
    Calculates the Decasteljau diagonals at point t from the given control polygon. 

    Parameters :
        Polygon : 2d ndarray of size 2xN.
        t       : point from 0 to 1 used for the linear map between two points. See dif()

    Returns:
     Coef : 3d ndarray where 
       * the first axis of dim 2 holds both diagonals
       * the second is of the same size as Polygon and contains the points
       * the third of dim 2 contains the coefficiants of the points
    """

    N = len(Polygon[0]) # number of points in the control polygon
    Polygon = Polygon.T
    Coef = np.zeros((2,N,2))
    Coef[0,0,:] = Polygon[0] 
    Coef[1,0,:] = Polygon[-1] 

    for i in range(1,N):
        DeCast = deCasteljau_nth(Polygon, i, t)
        Coef[0,i,:] = DeCast[0]
        Coef[1,i,:] = DeCast[-1]

    #flips the second diagonal
    Coef[1] = np.flipud(Coef[1])
    subdiv_pol = np.append(Coef[0], Coef[1], axis=0)
    
    return Coef, subdiv_pol

def DeCasteljau_plot(Polygon) :
    t=.7
    Diags, first = DeCasteljau(Polygon, t)    

    # Iterating the process, creating the second subdivision polynomial
    Diags2_first, diag2_left = DeCasteljau(Diags[0].T, t)
    Diags2_second, diag2_right = DeCasteljau(Diags[1].T, t)
    second = np.append(diag2_left, diag2_right, axis=0)

    # plotting the first diag
    plt.plot(first[:,0], first[:,1], 'o--', label="first subdivision polynomial")
    # plotting the second diag
    plt.plot(second[:,0], second[:,1], 'o--', label="second subdivision polynomial")

    plt.legend()
    plt.draw()

############## Acquisition pol ########################################

def AcquisitionPolygone(minmax,color1,color2) :
    x = []
    y = []
    coord = 0
    while coord != []:
        coord = plt.ginput(1, mouse_add=1, mouse_stop=3, mouse_pop=2)
        if coord != []:
            plt.draw()
            xx = coord[0][0]
            yy = coord[0][1]
            plt.plot(xx,yy,color1,ms=8);
            x.append(xx);
            y.append(yy);
            if len(x) > 1 :
                plt.plot([x[-2],x[-1]],[y[-2],y[-1]],color2)
    #Polygon creation
    Polygon = np.zeros((2,len(x)))
    Polygon[0,:] = x
    Polygon[1,:] = y
    return Polygon

# main part of the program to call AcquisitionPolygone.
fig2 = plt.figure()
ax = fig2.add_subplot(111)    
minmax = 10
ax.set_xlim((-minmax,minmax))
ax.set_ylim((-minmax,minmax))
plt.title("Polygon acquisition and Bezier curve")
Poly = AcquisitionPolygone(minmax,'or',':r')

PlotBezierCurve(Poly)
DeCasteljau_plot(Poly)
plt.waitforbuttonpress()
