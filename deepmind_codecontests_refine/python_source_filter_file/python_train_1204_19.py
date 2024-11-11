import sys
from functools import lru_cache, cmp_to_key
from heapq import merge, heapify, heappop, heappush
from math import ceil, floor, gcd, fabs, factorial, fmod, sqrt, inf
from collections import defaultdict as dd, deque, Counter as C
from itertools import combinations as comb, permutations as perm
from bisect import bisect_left as bl, bisect_right as br, bisect
from time import perf_counter
from fractions import Fraction
# sys.setrecursionlimit(pow(10, 6))
# sys.stdin = open("input.txt", "r")
# sys.stdout = open("output.txt", "w")
mod = pow(10, 9) + 7
mod2 = 998244353
def data(): return sys.stdin.readline().strip()
def out(*var, end="\n"): sys.stdout.write(' '.join(map(str, var))+end)
def l(): return list(sp())
def sl(): return list(ssp())
def sp(): return map(int, data().split())
def ssp(): return map(str, data().split())
def l1d(n, val=0): return [val for i in range(n)]
def l2d(n, m, val=0): return [l1d(n, val) for j in range(m)]


n = int(data())
arr = l()
dp = dd(int)
for i in range(n):
    if 1 < arr[i] <= 3:
        dp[arr[i]] += 1
        continue
    j = 2
    while j * j <= arr[i]:
        if arr[i] % j == 0:
            dp[j] += 1
        while arr[i] % j == 0:
            arr[i] //= j
        j += 1
    if arr[i] > 1:
        dp[arr[i]] += 1
answer = 0
for i in dp.values():
    answer = max(answer, i)
out(answer)
