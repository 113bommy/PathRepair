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


sys.setrecursionlimit(2147483647)
INF = 10 ** 13
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


n, k = LI()
acc = [[0] * 3 * k for _ in range(2 * k)]
for _ in range(n):
    x, y, c = LS()
    x = int(x); y = int(y)
    if c == 'W':
        x += k
    x %= 2 * k
    y %= 2 * k
    acc[y][x] += 1
    for i, j in ((1, 1), (1, -1), (-1, 1), (-1, -1), (2, 0)):
        if 0 <= y + k * i < 2 * k and 0 <= x + k * j < 3 * k:
            acc[y + k * i][x + k * j] += 1



acc = [[0] * (3 * k + 1)] + [list(accumulate([0] + acc[y])) for y in range(2 * k)]
for y in range(2 * k):
    for x in range(3 * k + 1):
        acc[y + 1][x] += acc[y][x]


ans = 0
for y in range(k + 1):
    for x in range(2 * k + 1):
        ans = max(ans, acc[y + k][x + k] - acc[y][x + k] - acc[y + k][x] + acc[y][x])


print(ans)