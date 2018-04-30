import numpy as np

import matplotlib.pyplot as plt 



imagen = np.loadtxt("datos.txt")

lon = len(imagen)

Ex = np.zeros([lon-1, lon-1])
Ey = np.zeros([lon-1, lon-1])
x = np.linspace(0.0, 512.0, lon-1)
y = np.linspace(0.0, 512.0, lon-1)

for i in range(1, lon-1):
    for j in range(1, lon-1):
        Ex[j-1][ i-1] = -(imagen[j+1][i] - imagen[j-1][ i])/2.0
        Ey[i-1][ j-1] = -(imagen[i][ j+1] - imagen[i][ j-1])/2.0
        

X, Y = np.meshgrid(x, y)

figura = plt.figure()

plt.imshow(imagen)
plt.colorbar()
ax = figura.add_subplot(111)

ax.streamplot(x, y, Ey, Ex)





plt.savefig("placas.pdf")
