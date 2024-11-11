from sys import stdin, exit, setrecursionlimit
setrecursionlimit(100000000)
from math import *
from bisect import bisect_left
from collections import deque

input = stdin.readline
lmi = lambda: list(map(int, input().split()))
mi = lambda: map(int, input().split())
si = lambda: input().strip('\n')
ssi = lambda: input().strip('\n').split()


n, m = mi()
a = [0]+lmi()+[m]
arr = [0]*(n+3)
arr2 = [0]*(n+3)
for i in range(1, n+2, 2):
    arr[i] += a[i] - a[i-1]
for i in range(2, n+2, 2):
    arr2[i] += a[i] - a[i-1]
for i in range(1, n+3):
    arr[i] += arr[i-1]
for i in range(n+1, -1, -1):
    arr2[i] += arr2[i+1]
ans = arr[-1]
for i in range(n+3):
    ans=max(ans, arr[i] + arr2[i] - 1)
print(ans)