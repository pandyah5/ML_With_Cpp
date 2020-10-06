import pandas as pd
import matplotlib.pyplot as plt

train = pd.read_csv(r'D:\DATA_BASE\Linear Regression Simple\train.csv')
test = pd.read_csv(r'D:\DATA_BASE\Linear Regression Simple\test.csv')
print(train.head())
print(test.head())

plt.figure(num=None, figsize=(18, 10), dpi=80, facecolor='w', edgecolor='k')
plt.plot(train['x'], train['y'], 'o')
plt.title("Train data")
plt.show()

plt.figure(num=None, figsize=(18, 10), dpi=80, facecolor='w', edgecolor='k')
plt.plot(test['x'], test['y'], 'o')
plt.title("Test data")
plt.show()