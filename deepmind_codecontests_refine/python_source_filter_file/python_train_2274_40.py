from functools import reduce
from math import gcd

N, K=map(int, input().split())
an=list(map(int,input().split()))

m = max(an)
g = reduce(lambda x, y: gcd(x, y), an)

if K <=m and K % g == 0:
    print ('POSSIBLE')
else:
    print ('IMPOSSIBLE')