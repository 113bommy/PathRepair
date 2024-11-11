from math import *
m31 = [1, 3, 5, 7, 8, 10, 12]
m30 = [4, 6, 9, 11]
m29 = [2]
m, d = [int(i) for i in input().split()]

if m in m31:
    d = 23 + d
    print(ceil(d / 7) + 1)
elif m in m30:
    d = 22 + d
    print(ceil(d / 7) + 1)
else: d += 21; print(ceil(d/7) + 1)
    
