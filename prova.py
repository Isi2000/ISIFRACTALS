import numpy as np
import matplotlib.pyplot as plt
a = np.loadtxt('isi.txt') #usecols = np.arange(0,20))
plt.imshow(a, cmap = "rainbow")
plt.axis('off')
plt.show()

