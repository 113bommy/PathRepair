"""
    Template written to be used by Python Programmers.
    Use at your own risk!!!!
    Owned by adi0311(rating - 1989 at CodeChef and 1405 at CodeForces).
"""

import sys
from bisect import bisect_left as bl, bisect_right as br, bisect  # Binary Search alternative
import math
from timeit import default_timer as dt  # To get the running time of a program
from itertools import zip_longest as zl  # zl(x, y) return [(x[0], y[0]), ...]
from itertools import groupby as gb  # gb(x, y)
from itertools import combinations as comb  # comb(x, y) return [all subsets of x with len == y]
from itertools import combinations_with_replacement as cwr
from collections import defaultdict as dd  # defaultdict(<datatype>) Free of KeyError.
from collections import deque as dq  # deque(list) append(), appendleft(), pop(), popleft() - O(1)
from collections import Counter as c  # Counter(list)  return a dict with {key: count}
# sys.setrecursionlimit(2*pow(10, 6))
# sys.stdin = open("input.txt", "r")
# sys.stdout = open("output.txt", "w")
mod = pow(10, 9) + 7
mod2 = 998244353
# def data(): return sys.stdin.readline().strip()
# def out(var): sys.stdout.write(var)
def data(): return input()
def l(): return list(sp())
def sl(): return list(ssp())
def sp(): return map(int, data().split())
def ssp(): return map(str, data().split())
def l1d(n, val=0): return [val for i in range(n)]
def l2d(n, m, val=0): return [[val for i in range(n)] for j in range(m)]


for _ in range(int(data())):
    n, s, k = sp()
    arr = set(l())
    result = mod
    for i in range(max(1, s-10000), min(n, s+10000)):
        if i not in arr:
            result = min(abs(s-i), result)
    print(result)