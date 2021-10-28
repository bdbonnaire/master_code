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

ax1.legend()
fig.show()
#fig.savefig("exact_plot")
