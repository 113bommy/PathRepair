from collections import deque, defaultdict, Counter
from itertools import product, groupby, permutations, combinations
from math import gcd, floor, inf
from bisect import bisect_right, bisect_left

n, k = map(int, input().split())

if k <= n:
    print((k-1)//2)
else:
    ans = max(0, (k-1)//2 - (k-n))
    print(ans)

