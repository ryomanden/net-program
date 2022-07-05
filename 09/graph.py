from sqlite3 import DatabaseError
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
fig = plt.figure(dpi=120)

# open file #
bubble = pd.read_csv('b_result.csv', encoding = 'UTF-8')
select = pd.read_csv('s_result.csv', encoding = 'UTF-8')

print(bubble)
print(select)

# col select #
column1_bubble = bubble[bubble.keys()[0]]
column2_bubble = bubble[bubble.keys()[1]]

column1_select = select[select.keys()[0]]
column2_select = select[select.keys()[1]]


# LAVEL #
plt.xlabel(bubble.keys()[0])
plt.ylabel(bubble.keys()[1])

# Plot #
plt.plot(column1_bubble, column2_bubble, linestyle='solid', marker='o')
plt.plot(column1_select, column2_select, linestyle='solid', marker='o')

# Han rei #
plt.legend(["Bubble sort", "Select sort"])

fig.savefig("img.png")