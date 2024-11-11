import sys
import bisect
# import heapq
from math import ceil,floor


RI = lambda : [int(x) for x in sys.stdin.readline().split()]
ri = lambda : sys.stdin.readline().strip()
mod = 10**9+7
# for _ in range(int(ri())):
n = int(ri())
a = RI()

pre = [1] *(n+1)
suf = [1]*(n+1)

for i in range(n):

    pre[i+1] = ~a[i]&pre[i]
for i in range(n-1,-1,-1):
    suf[i] = suf[i+1]&(~a[i])

ans = -1
posans = 0
for i in range(len(a)):
    if pre[i] & suf[i+1] & a[i] > ans:
        ans = pre[i] & suf[i+1] & a[i]
        posans = i

print(a[posans],end=" " )
for i in range(len(a)):
    if i != posans:
        print(a[i],end=" ")


print()


    