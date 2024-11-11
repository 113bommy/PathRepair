from collections import defaultdict, deque, Counter
from heapq import heappush, heappop, heapify
import math
import bisect
import random
from itertools import permutations, accumulate, combinations, product
import sys
import string
from bisect import bisect_left, bisect_right
from math import factorial, ceil, floor
from operator import mul
from functools import reduce
from operator import mul


sys.setrecursionlimit(2147483647)
INF = 10 ** 20
def LI(): return list(map(int, sys.stdin.buffer.readline().split()))
def I(): return int(sys.stdin.buffer.readline())
def LS(): return sys.stdin.buffer.readline().rstrip().decode('utf-8').split()
def S(): return sys.stdin.buffer.readline().rstrip().decode('utf-8')
def IR(n): return [I() for i in range(n)]
def LIR(n): return [LI() for i in range(n)]
def SR(n): return [S() for i in range(n)]
def LSR(n): return [LS() for i in range(n)]
def SRL(n): return [list(S()) for i in range(n)]
def MSRL(n): return [[int(j) for j in list(S())] for i in range(n)]
mod = 1000000007

n = I()
X = LI()
l = I()
log_n = (n - 1).bit_length()
doubling = [[n] * n for _ in range(log_n)]
for i in range(n - 1):
    doubling[0][i] = bisect_right(X, X[i] + l) - 1

for j in range(1, log_n):
    for k in range(n):
        if doubling[j - 1][k] == n:
            continue
        doubling[j][k] = doubling[j - 1][doubling[j - 1][k]]
q = I()
for _ in range(q):
    a, b = LI()
    if a > b:
        a, b = b, a
    a -= 1
    b -= 1
    ans = 0
    for m in range(log_n - 1, -1, -1):
        if doubling[m][a] <= b:
            a = doubling[m][a]
            ans += 2 ** m
    print(ans)






