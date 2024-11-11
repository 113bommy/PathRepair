MOD = 10**9 + 7
I = lambda:list(map(int,input().split()))
from math import *

n, k = I()
l = list(set(I()))
l.sort()
i = 0
j = 0
sub = 0
while i < len(l) and i < k:
    print(l[i] - sub)
    sub += l[i]
    i += 1
while i < k:
    print(0)
    i += 1
