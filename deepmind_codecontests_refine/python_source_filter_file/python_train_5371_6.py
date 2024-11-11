import math
import sys
from bisect import bisect_right, bisect_left, insort_right
from collections import Counter, defaultdict
from heapq import heappop, heappush
from itertools import accumulate, permutations, combinations
from sys import stdout

R = lambda: map(int, input().split())
n = int(input())
a = list(R())
g = a[0]
for x in a[1:]:
    g = math.gcd(g, x)
if g > 1:
    print('YES')
    print(0)
    exit(0)
cnt = 0
i = 0
while i < n:
    if a[i] % 2:
        cnt += 1 if i == n - 1 or a[i + 1] % 2 else 2
        i += 1 if i == n - 1 or a[i + 1] % 2 == 0 else 2
    else:
        i += 1
print('YES')
print(cnt)