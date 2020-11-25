import matplotlib.pyplot as plt
import pandas as pd

data = pd.read_csv("train.csv");
data.shape[0]

for i in range(data.shape[0] - 4):
    if (data['id'][i] == 1 or data['id'][i] == 2):
        plt.plot(data['x'][i], data['y'][i], 'o', color = "red" if data['id'][i] == 1 else "blue")
    else:
        plt.plot(data['x'][i], data['y'][i], 'o', color = "green" if data['id'][i] == 3 else "yellow")


plt.plot(data['x'][i], data['y'][i], 'X', color = "black")
plt.plot(data['x'][i + 1], data['y'][i + 1], 'X', color = "black")
plt.plot(data['x'][i + 2], data['y'][i + 2], 'X', color = "black")
plt.plot(data['x'][i + 3], data['y'][i + 3], 'X', color = "black")

plt.show()
