from collections import defaultdict
import math
import sys
N,P=[int(x) for x in input().split()]
if N==1:
    print(P)
    sys.exit(0)
now = P
d = defaultdict(int)

for i in range(2,int(math.sqrt(P))+1):
    while  now%i==0:
        now /= i
        d[i]+=1
ans=1
for k in d:
    if d[k] // N > 0:
        ans *= (k * (d[k] // N))
print(ans)
