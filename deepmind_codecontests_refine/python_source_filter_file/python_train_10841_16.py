from math import sqrt, ceil, floor
from sys import stdin, stdout
from heapq import heapify, heappush, heappop
import string

n = int(stdin.readline())
a = list(map(int, stdin.readline().split()))
ans = 0
for i in range(n):
    if a[0] != a[i]:
        ans = max(ans, i - 1)
    if a[-1] != a[i]:
        ans = max(ans, n - i - 1)

stdout.write("%d" % ans)
