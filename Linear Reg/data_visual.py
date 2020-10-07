import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

## Reading CSV's from local address
train = pd.read_csv(r'D:\DATA_BASE\Linear Regression Simple\train.csv') ## Change as per location on your device
test = pd.read_csv(r'D:\DATA_BASE\Linear Regression Simple\test.csv') ## Change as per location on your device
print(train.describe())
print(test.describe())

## Model Parameters obtained by training the model
x = np.linspace(0, 100, 10000);
y = 0.984304*x + 0.984304;

## Plotting train data and the model prediction
plt.figure(num=None, figsize=(18, 10), dpi=80, facecolor='w', edgecolor='k')
plt.plot(train['x'], train['y'], 'o', label = "Actual Value")
plt.plot(x, y, color = "red", linewidth = 5, label = "Model Prediction")
plt.legend()
plt.title("Train data")
plt.show()

## Plotting test data and the model prediction
plt.figure(num=None, figsize=(18, 10), dpi=80, facecolor='w', edgecolor='k')
plt.plot(test['x'], test['y'], 'o', label = "Actual Value")
plt.plot(x, y, color = "red", linewidth = 5, label = "Model Prediction")
plt.legend()
plt.title("Test data")
plt.show()
