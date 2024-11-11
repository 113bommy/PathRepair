from collections import Counter
from itertools import accumulate
import bisect

n = int(input())
a = list(map(int, input().split()))
b = sorted(Counter(a).values())
exist = len(b)
b = [0]*(n-exist)+b
c = list(accumulate([0]+b))

print(n)
for k in range(2,n//2+1):
    l = 0
    r = n+1
    while r-l>1:
        x = (r+l)//2
        i = bisect.bisect_left(b,x)
        if c[i]+(n-i)*x>=x*k:
            l = x
        else:
            r = x
    print(l)

for k in range(max(n//2+1,2),n+1):
    if exist>=k:
        print(1)
    else:
        print(0)

