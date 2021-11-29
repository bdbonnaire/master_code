import numpy as np
import matplotlib.pyplot as plt
from matplotlib import ticker
from matplotlib.patches import Rectangle
import scipy.fftpack as fftp



# import the cameraman image using pyplot.
# image is a 256x256 ndarray where each value represents pixels
# in the picture and its contrast from 0 to 1.
image = plt.imread("cameraman.png")
L = 256

####################### Application of the DCT #########################
dct_image = np.zeros((L,L))

for i in np.arange(0,L,8):
    for j in np.arange(0,L,8):
        dct_image[i:i+8, j:j+8] += fftp.dctn(image[i:i+8, j:j+8], norm='ortho')


######################### Quantization ##################################

def quantize(q, dct_image):
# Quantization Matrix 
    Q = np.ones((8,8))
    for i in range(8):
        for j in range(8):
            Q[i,j] += q*(1+i+j)


# Quantization
    for i in np.arange(0,L,8):
        for j in np.arange(0,L,8):
            dct_image[i:i+8, j:j+8] /= Q

##### calculation of the ratio
# counts the occurence of 0 in the dct
    ratio = 0
    for i in dct_image.ravel():
        if i <= 1E-5 :
            ratio += 1

# calculates the ratio with the size of the image L²
    ratio /= L**2
    return ratio, dct_image

q_val = np.arange(20)
q_ratio = np.zeros(20)
for i in range(20):
    q_ratio[i] = quantize(q_val[i], dct_image)[0]

################ Plot of the Ratio #############################
fig, ax = plt.subplots()
ax.plot(q_val, q_ratio)
ax.xaxis.set_major_locator(ticker.MultipleLocator(2))
ax.yaxis.set_major_formatter(ticker.PercentFormatter(1))
ax.set_xlabel("Values of q")
ax.set_ylabel("Ratio of zeros")

plt.show()


################ Plot of the Comparison ##############################
#fig, axes = plt.subplots(2,2)
#axes = axes.ravel()
#
#plt.set_cmap('Greys_r')
#axes[0].imshow(image)
#axes[0].add_patch(Rectangle((144,56), 8, 8, fill=False, color='orange'))
#axes[0].axis('off')
#
#axes[1].imshow(dct_image)
#axes[1].add_patch(Rectangle((144,56), 8, 8, fill=False, color='orange'))
#axes[1].axis('off')
#
#axes[2].imshow(image[144:152, 56:64])
#axes[2].axis('off')
#
#axes[3].imshow(dct_image[144:152, 56:64])
#axes[3].axis('off')
#plt.show()
