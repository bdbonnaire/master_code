# Provides an animation of de Casteljau algorithm

import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation


def dif(points, t):
# points is an np array containing the current control polygon
# dif returns an np array of Y(t) where
# [0,1] --> R²
# Y(t) = t*Ai + (1-t)*Ai+1
    return np.array([((1-t)*points[i] + t*points[i+1]) for i in range(len(points)-1)])

def deCasteljau_nth(control, n:int, t):
    P = control
    for i in range(n):
        P=dif(P,t)

    return P

def polygon_plotter(t, control):
# polygon_plotter plots all the polygon from the de casteljau algorithm
# The last point is plotted as a red dot

    for i in range(len(control)):
        Qi = deCasteljau_nth(control,i,t)
        if len(Qi) != 1:
            ax.plot([Qi[i][0] for i in range(len(Qi))],
                [ Qi[i][1] for i in range(len(Qi))],
                'x-')
        else:
            ax.plot(Qi[0][0], Qi[0][1], 'ro')
    
# control polygon
cpol = np.array([(0,0), (1,2), (2,2), (3,1)])
animate = lambda t: polygon_plotter(t, cpol)

fig, ax = plt.subplots()

ani = FuncAnimation(fig, animate, frames=np.linspace(0,1,300))
plt.show()
#fig.show()
#fig.savefig("bezierplot")
