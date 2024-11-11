import sys
input = sys.stdin.readline
# sys.setrecursionlimit(400000)
def I(): return input().strip()
def II(): return int(input().strip())
def LI(): return [*map(int, input().strip().split())]
import copy, string, math, time, functools, random, fractions
from heapq import heappush, heappop, heapify
from bisect import bisect_left, bisect_right
from collections import deque, defaultdict, Counter, OrderedDict
from itertools import permutations, combinations, groupby
from operator import itemgetter


for _ in range(II()):
    n, k = LI()
    a = LI()
    c = Counter(a)
    ans = [0] * n
    var = 0
    for i in c.values():
        var += min(k, i)
    mex = (var // k) * k
    tot = 0
    dd = defaultdict(lambda: 0)
    color = 0
    sor_ind, sor_arr = list(zip(*sorted(enumerate(a), key=lambda x: x[1])))
    # print(sor_arr)
    # print(sor_ind)
    for i in range(n):
        if tot >= mex:
            break
        if dd[sor_arr[i]] >= k:
            continue
        ans[i] = color % k + 1
        color += 1
        dd[sor_arr[i]] += 1
        # print(dd[sor_arr[i]])
        tot += 1
    out = [0] * n
    # print(ans)
    for i in range(n):
        out[sor_ind[i]] = ans[i]
    print(*out)
