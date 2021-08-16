import numpy              as np 
import matplotlib.pyplot  as plt 
from mpl_toolkits.mplot3d import Axes3D

# Load the data
x,y,z = np.loadtxt("results.txt",delimiter=",",unpack=True)

# Plot the results
fig = plt.figure(figsize=(15,20))
fig.suptitle('Lorenz\'s attractor', fontsize=20)
ax = fig.add_subplot(2, 3, 1)
plt.plot(x,y)
plt.xlabel('x', fontsize=15)
plt.ylabel('y', fontsize=15)
ax = fig.add_subplot(2, 3, 2)
plt.plot(x,z)
plt.xlabel('x', fontsize=15)
plt.ylabel('z', fontsize=15)
ax = fig.add_subplot(2, 3, 3)
plt.plot(y,z)
plt.xlabel('y', fontsize=15)
plt.ylabel('z', fontsize=15)
ax = fig.add_subplot(2, 3, 5, projection='3d')
plt.plot(x, y, z)
ax.set_xlabel('x', fontsize=15)
ax.set_ylabel('y', fontsize=15)
ax.set_zlabel('z', fontsize=15)
plt.show()
