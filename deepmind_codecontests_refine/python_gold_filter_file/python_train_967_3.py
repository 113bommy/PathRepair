import sys
from functools import lru_cache, cmp_to_key
from heapq import merge, heapify, heappop, heappush
from math import ceil, floor, gcd, fabs, factorial, fmod, sqrt, inf, log, pi, sin
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


s = data()
a, b = s.split(':')
start = 1
for i in a:
    if i.isalpha():
        temp = (ord(i) - 65) + 10
    else:
        temp = int(i)
    start = max(temp, start)
for i in b:
    if i.isalpha():
        temp = (ord(i) - 65) + 10
    else:
        temp = int(i)
    start = max(temp, start)
time = set()
answer = []
for base in range(start + 1, 1001):
    hour = 0
    for i in range(len(a)-1, -1, -1):
        if a[i].isalpha():
            temp = (ord(a[i])-65) + 10
        else:
            temp = int(a[i])
        hour += temp * pow(base, len(a)-i-1)
    if hour > 23:
        continue
    minute = 0
    for i in range(len(b)-1, -1, -1):
        if b[i].isalpha():
            temp = (ord(b[i])-65) + 10
        else:
            temp = int(b[i])
        minute += temp * pow(base, len(b)-i-1)
    if minute > 59:
        continue
    temp = str(hour) + ":" + str(minute)
    if temp in time:
        out(-1)
        exit()
    answer.append(base)
    time.add(temp)
if not answer:
    out(0)
    exit()
out(*answer)
