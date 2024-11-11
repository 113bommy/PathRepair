from math import *

n, v = map(int,input().split())
if n < v:
    print(n)
else:
    print(v + (n - v) * (n - v + 1) // 2 - 1)