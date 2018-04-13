import sys
import math 
import numpy as np
import matplotlib.pyplot as plt

matrix = np.loadtxt(sys.argv[1], dtype = int, skiprows = 1)
verticles = matrix.shape[0]

x = []
y = []
radius = 0.5 * verticles

for i in range(verticles):
	x.append(radius * math.cos(i * 2.0 * math.pi / verticles))
	y.append(radius * math.sin(i * 2.0 * math.pi / verticles))

#setting figure size and drawing verticles
fig = plt.figure(figsize = (10, 10), dpi = 100)
plt.scatter(x, y, c = 'r')

rows = matrix.shape[0]
columns = matrix.shape[1]

#drawing edges
for j in range(columns):
	edge_x = []
	edge_y = []
	for i in range(rows):
		if(matrix[i][j] == 1):
			edge_x.append(x[i])
			edge_y.append(y[i])
	plt.plot(edge_x, edge_y, c = 'k')

plt.show()