import pandas as pd

data = pd.read_csv(r'D:\DATA_BASE\bank_default_binary\bank.csv')
data.head()
data['default'] = data['default'].replace({'no': -1, 'yes': 1})
data['marital'] = data['marital'].replace({'married': 1, 'single': 0, 'divorced': -1})
data['housing'] = data['housing'].replace({'no': -1, 'yes': 1})
data['loan'] = data['loan'].replace({'no': -1, 'yes': 1})
data['y'] = data['y'].replace({'no': -1, 'yes': 1})
del data['job']
del data['day']
del data['campaign']
del data['pdays']
del data['poutcome']
del data['education']
del data['contact']
del data['month']
data.head()
##data.to_csv("test.csv")


data = pd.read_csv(r'D:\DATA_BASE\bank_default_binary\bank-full - orginal.csv')
data.head()
data['default'] = data['default'].replace({'no': -1, 'yes': 1})
data['housing'] = data['housing'].replace({'no': -1, 'yes': 1})
data['loan'] = data['loan'].replace({'no': -1, 'yes': 1})
data['y'] = data['y'].replace({'no': -1, 'yes': 1})
del data['job']
del data['day']
del data['campaign']
del data['pdays']
del data['poutcome']
del data['education']
del data['contact']
del data['month']
data.describe()
##data.to_csv("train.csv")


import pandas as pd
import numpy as np
import matplotlib.pyplot as plt

test = pd.read_csv("train_custom.csv")
plt.plot(np.array(test['x'][0:2000]), np.array(test['y'][0:2000]),'o', color = "blue")
plt.plot(np.array(test['x'][2001:4000]), np.array(test['y'][2001:4000]),'o', color = "red")
plt.xlim(-10, 10)
plt.show()

test1 = pd.read_csv("test_custom.csv")
plt.plot(np.array(test1['x'][1:1000]), np.array(test1['y'][1:1000]),'o', color = "blue")
plt.plot(np.array(test1['x'][1001:2000]), np.array(test1['y'][1001:2000]),'o', color = "red")
plt.xlim(-10, 10)
plt.show()
