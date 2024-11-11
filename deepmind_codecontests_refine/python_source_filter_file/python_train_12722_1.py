from collections import Counter
from math import ceil
t = int(input())
for _ in range(0,t):
    n = int(input())
    ss = [int(i) for i in input().split()]
    c = Counter(ss)
    aa = sorted([int(i) for i in c.values()])
    maxx = 10**9+7
    for i in range(1,aa[0]+2):
        val = True
        pos = []
        for ii in aa:
            k = ceil(ii/i)
            if k*i - ii <= 1:
                pos.append(k)
            else:
                val = False
                break
        if val:
            maxx = min(maxx,sum(pos))
    print(maxx)