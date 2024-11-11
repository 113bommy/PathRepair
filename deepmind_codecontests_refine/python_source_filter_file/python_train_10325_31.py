from statistics import mode
from collections import Counter

n = int(input(''))
a = [int(x) for x in str(input('')).split(' ')]

maximum = -1
for i in range (1, n):
    if a[i]>maximum:
        maximum = a[i]
    
if sum(a) % 2 == 0 and sum(a)-maximum>=maximum:
    print('YES')
else:
    print('NO')