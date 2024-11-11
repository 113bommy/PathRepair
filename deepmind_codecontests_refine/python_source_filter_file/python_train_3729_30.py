from collections import defaultdict
from bisect import bisect
n,m=map(int,input().split())
l=[list(map(int,input().split()) for _ in range(m))]
a=defaultdict(list)
for x,y in sorted(l):
    a[x]+=[y]

for x,y in l:
    z=bisect(a[x],y)
    print('%06d%06d'%(x,z))