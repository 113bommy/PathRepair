"""
    Template written to be used by Python Programmers.
    Use at your own risk!!!!
    Owned by enraged(rating - 5 star at CodeChef and Specialist at Codeforces).
"""
import sys
import heapq
from math import ceil, floor, gcd, fabs, factorial, fmod
from collections import defaultdict as dd, deque, Counter as c
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


p, d = ssp()
d = int(d)
temp = int(p)
k = int(p)
i = 1
while i <= len(p):
    if p[-i] != '9':
        k = k-(int(p[-i])+1)*pow(10, i-1)
        if temp-k <= d:
            p = str(k)
        else:
            break
    i += 1
out(str(p))
