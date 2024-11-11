from math import *
from bisect import bisect_right as br 

g = gcd(*map(int,  input().split()))
i = 1
L = []
while (i*i <= g):
    if g % i == 0:
        L.append(i // 1)
        L.append(g // i)
    i += 1
L = sorted(L)
n=int(input())
for i in  range(n):
    l, h = map(int,  input().split())
    m = L[br(L, h) - 1]
    if m < l :
        print (-1)
    else:
        print(m)
