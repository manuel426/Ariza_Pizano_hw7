import numpy as np
import matplotlib.pyplot as plt
import sys
import pylab as py

data=np.loadtxt(sys.argv[1])

f, ((ax1, ax2), (ax3, ax4)) = plt.subplots(2, 2)
ax1.plot(data[:,0], data[:,1])
ax1.set_title('Sod_test_tube')
ax2.plot(data[:,0], data[:,2])
ax3.plot(data[:,0], data[:,3])

plt.savefig(sys.argv[0]+"."+sys.argv[1]+".pdf")
