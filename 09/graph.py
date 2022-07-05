import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
fig = plt.figure(dpi=120)

data = pd.read_csv('b_result.csv', encoding = 'UTF-8')

int result[]
print(data)

for i in data:
    
data_x = data[data.columns[1]]
data_y = data[data.columns[2]]

plt.plot(data_x, data_y, linestyle='solid', marker='o')

fig.savefig("img.png")