import numpy as np

import matplotlib.pyplot as plt

q2 = np.loadtxt("caos.txt")[:, 0]

p2 = np.loadtxt("caos.txt")[:, 1]


plt.plot(p2, q2)
plt.savefig("caos.pdf")
