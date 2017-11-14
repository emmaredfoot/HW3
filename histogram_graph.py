import numpy as np
import matplotlib.pyplot as plt
import plotly.plotly as py
import sys
import csv


f = open(sys.argv[1], 'rt')
A=[]
try:
    reader = csv.reader(f)
    for row in reader:
        A.append(float(row[0]))
finally:
    f.close()

bin_groups = np.linspace(0, 1, 101)
print(bin_groups)

plt.hist(A, bins=bin_groups)
plt.title("Random Number Generator Histogram")
plt.xlabel("Value")
plt.ylabel("Frequency")

plt.show()

fig = plt.gcf()
plot_url = py.plot_mpl(fig, filename='histogram_60_RNG')
