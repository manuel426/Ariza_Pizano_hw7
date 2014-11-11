import sys
import matplotlib.pyplot as plt
import numpy as np
from mpl_toolkits.mplot3d import Axes3D

#Importa el archivo
filename = sys.argv[1]

matriz = np.loadtxt(filename)
u = matriz


x,y=u.shape

X = range(x)
Y = range(y)
fig = plt.figure()
axes = fig.add_subplot(111, projection='3d')
X, Y = np.meshgrid(X, Y)
axes.plot_surface(X, Y, u)
axes.set_xlabel('posicion')
axes.set_ylabel('tiempo')
axes.set_zlabel('velocidad')
plt.savefig(filename + '.pdf',format = 'pdf')
plt.show()

