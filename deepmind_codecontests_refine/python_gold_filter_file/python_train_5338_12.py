from collections import defaultdict as dd
from sys import stdin,stdout
from bisect import bisect_left
from math import log,sqrt


n = int(input())
a = list(map(int, input().split()))
ans = [0]*n
a.sort()
k = 0
for i in range(1,n,2):
    ans[i] = a[k]
    k+=1
for i in range(0,n,2):
    ans[i] = a[k]
    k+=1
print((n-1)//2)
print(*ans)