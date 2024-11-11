"""
    Template written to be used by Python Programmers.
    Use at your own risk!!!!
    Owned by adi0311(rating - 1989 at CodeChef and 1449 at Codeforces).
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


n, m = sp()
arr = l()
arr.sort()
if 1 in arr or n in arr:
    out("NO")
    exit()
for i in range(len(arr)-2):
    a, b = arr[i+2]-arr[i+1], arr[i+1]-arr[i]
    if a == 1 and b == 1:
        out("NO")
        exit()
out("YES")
