from collections import deque, defaultdict, Counter
from itertools import product, groupby, permutations, combinations
from math import gcd, floor, inf, log2, sqrt, log10
from bisect import bisect_right, bisect_left
from statistics import mode
from string import ascii_uppercase

cases = int(input())
ans = None
best = -inf
for _ in range(cases):
    arr = list(input().split())
    plus, minus, a, b, c, d, e = map(int, arr[1:])
    score = a+b+c+d+e + plus*100 - minus*50
    if score > best:
        ans = arr[0]
        best = score

print(ans)

