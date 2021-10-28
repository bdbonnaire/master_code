import numpy as np
import matplotlib.pyplot as plt

np.random.seed(0)

N=11

X = np.linspace(0,1,N)
noise = np.random.uniform(-0.2, 0.2, N)

Y = 2*X + 3 + noise

F = np.ones((2,N), dtype = 'float')
F[1] = Y
#A = np.matmul(np.transpose(F),F)
#print(A.shape)
#print((F.T).shape)
#print(Y.shape)
#B = np.matmul(F.T,Y)

A = np.array([[N,np.sum(X)], [np.sum(X), np.linalg.norm(X)**2]], dtype= 'float')
B = np.array([np.sum(Y), np.inner(X,Y)], dtype= 'float')

L = np.linalg.inv(A).dot(B)
#L = np.linalg.solve(A,B)
f = lambda x : L[0] + L[1]*x
x = np.linspace(0,1,2)

######### Error calculations ######################
#
r = Y-f(X)
eps1 = np.linalg.norm(r, ord=0)/N
eps2 = np.linalg.norm(r, ord=2)/(N**(1/2))
epsinf = np.linalg.norm(r, ord=np.inf)

print(eps1, eps2)

plt.plot(x, f(x), 'r-')
plt.plot(X, Y,'bo')
plt.text(0.5,0.5, '$\epsilon_1 =$ ' + str(eps1) + '\n $\epsilon_2 = $' + str(eps2) + '\n $\epsilon_\infty = $' + str(epsinf), bbox=dict(ec='black')) 

plt.show()
