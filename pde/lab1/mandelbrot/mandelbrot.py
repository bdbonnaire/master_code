import numpy as np
import matplotlib.pyplot as plt

def nbrIter(c:complex, threshold:int=4, maxSteps:int=25) -> int:
    z=c
    i=1
    while i<maxSteps and (z*z.conjugate()).real<threshold:
            z=z*z + c
            i+=1
    return i

def plotter(n, threshold, maxSteps=25):
    mx = 2.48 / n
    my = 2.26 / n
# quickly creates a function that maps image coords to the complex plane window
    mapper = lambda x,y: (mx*x -2, my*y - 1.13) 
    img=np.full((n,n), 255)
    for x in range(n):
        for y in range(n):
            it = nbrIter(complex(*mapper(x,y)), threshold= threshold, maxSteps=maxSteps)
            img[y][x] = 255 -it
    return img

#img = plotter(1000, threshold=4, maxSteps=50)
#plt.imshow(img, cmap="plasma")
#plt.axis("off")
#plt.show()

img = plotter(500,4,50)
plt.imshow(img, cmap="inferno")
plt.axis("off")
plt.show()
