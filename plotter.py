import numpy as np
import matplotlib.pyplot as plt
import os
import glob #python library that behaves like linux

data_unsorted = np.array(glob.glob('./output_scaling*.txt'))

data_sorted = np.sort(data_unsorted)

data = data_sorted[::-1]
print(data)

for d in data:
    f = np.loadtxt(d)
    plt.imshow(f, cmap = "rainbow")
    plt.axis('off')
    plt.pause(0.1)
