import os
import math
import time
s5 = []
s2 = []
res = []
a = int(input())
for i in range(500):
    s5.append(5**i)
    s2.append(2**i)
ar = [0]*1000010
for i in range(1,1000000):
    a3 = 0
    a2 = 0
    for j in range(1,500):
        if i//s5[j]>0:
            a3+=i//s5[j]
        else:
            break
    for j in range(1,500):
        if i //s2[j]>0:
            a2+=i//s2[j]
        else:
            break
    ar[i]=min(a2,a3)
    if ar[i]>a:
        break
    if ar[i]== a:
        res.append(i)
print(len(res))
for i in res:
    print(i, end=' ')