from collections import deque, defaultdict, Counter
from itertools import product, groupby, permutations, combinations
from math import gcd, floor, inf, log2, sqrt, log10
from bisect import bisect_right, bisect_left

n, t = map(int, input().split())
prev = 0
ans = -1
first = True
for _ in range(n):

    hour, minute = map(int, input().split())

    cur = hour*60 + minute

    if first:
        if cur > t:
            ans = 0
            break
        first = False
    if cur - prev >= t * 2+1:
        # print(cur-prev)
        # print(t*2+1)
        ans = prev + t
        break
    else:
        prev = cur+1
if ans == -1:
    ans = cur + t+1

print(ans//60, ans%60)






