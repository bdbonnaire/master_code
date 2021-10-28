#plots a line graph of the square function from a simple list

import matplotlib.pyplot as plt

input_values=[1, 2, 3, 4, 5]
squares = [1, 4, 9, 16, 25]
plt.plot(input_values, squares)

# a bit of styling
plt.title("Square numbers", fontsize=24)
plt.xlabel("Value", fontsize=14)
plt.ylabel("Value squared", fontsize=14)
plt.tick_params(axis="both", labelsize=14)

plt.show()
