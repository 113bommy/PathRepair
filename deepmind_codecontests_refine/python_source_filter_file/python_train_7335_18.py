"""
    Template written to be used by Python Programmers.
    Use at your own risk!!!!
    Owned by adi0311(rating - 5 star at CodeChef and Specialist at Codeforces).
"""
import sys
import bisect
import heapq
from math import *
from collections import defaultdict as dd  # defaultdict(<datatype>) Free of KeyError.
from collections import deque  # deque(list) append(), appendleft(), pop(), popleft() - O(1)
from collections import Counter as c  # Counter(list)  return a dict with {key: count}
from itertools import combinations as comb
from bisect import bisect_left as bl, bisect_right as br, bisect
# sys.setrecursionlimit(2*pow(10, 6))
# sys.stdin = open("input.txt", "r")
# sys.stdout = open("output.txt", "w")
mod = pow(10, 9) + 7
mod2 = 998244353
def data(): return sys.stdin.readline().strip()
def out(var): sys.stdout.write(var)
def l(): return list(map(int, data().split()))
def sl(): return list(map(str, data().split()))
def sp(): return map(int, data().split())
def ssp(): return map(str, data().split())
def l1d(n, val=0): return [val for i in range(n)]
def l2d(n, m, val=0): return [[val for i in range(n)] for j in range(m)]


n = int(data())
first, second = [], []
f, s = 0, 0
for i in range(n):
    a = int(data())
    if a < 0:
        second.append(abs(a))
        s += abs(a)
        continue
    first.append(a)
    f += a
if s > f:
    out("second")
    exit()
if f > s:
    out("first")
    exit()
if first == second:
    if a < 0:
        out("second")
        exit()
    out("first")
    exit()
for i in range(min(len(first), len(second))):
    if first[i] > second[i]:
        out("first")
        exit()
    if second[i] < second[i]:
        out("second")
        exit()
