import numpy as np
import matplotlib.pyplot as plt

def nbrIter(c:complex, radius:int=4, maxSteps:int=25) -> int:
    z=c
    i=1
    while i<maxSteps and (np.abs(z)<radius:
            z=z*z + c
            i+=1
    return i

def plotter(n, radius, maxSteps=25):

