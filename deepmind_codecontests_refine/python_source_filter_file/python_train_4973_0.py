import sys
import bisect
# import heapq
from math import ceil,floor


def check(k,n):
    fr = 0
    temp=  n
    while ( n > 0):
        if n < k :
            fr = fr+n
            n = 0
        else:
            fr = fr + k
            n = n-k
            n -= (n//10)
    return fr*2>= temp

RI = lambda : [int(x) for x in sys.stdin.readline().split()]
ri = lambda : sys.stdin.readline().strip()
mod = 10**9+7
# for _ in range(int(ri())):

n = int(ri())
l = 1
r = n
ans = 10**10
while ( l <= r):
    mid = (l+r)//2
    if check(mid,n):
        r = mid-1
        ans = min(ans,mid)
    else:
        l = mid+1
print(ans)