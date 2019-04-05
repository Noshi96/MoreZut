import numpy as np
import matplotlib.pyplot as plot
import matplotlib.image as image

obraz=image.imread('bo.jpg')
obraz=obraz[:,:,0]
obraz2=np.zeros([obraz.shape[0],obraz.shape[1]])

for x in range(0,obraz.shape[0]):
    for y in range(0,obraz.shape[1]):
        obraz2[x,y] = obraz[x,y]+np.random.rand(1)

plot.subplot(121)
plot.imshow(obraz)
plot.subplot(122)
plot.imshow(obraz2)
plot.show()







        
