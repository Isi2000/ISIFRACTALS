import imageio
import os
import numpy as np
path = '/home/isacco/ISIFRACTALS/PLOT/'
filenames_ = os.listdir(path)
filenames = np.sort(filenames_)
img = []

for fn in filenames:
    
    img.append(imageio.imread(path + fn))

imageio.mimsave('zoom.gif', img, duration = 2)
