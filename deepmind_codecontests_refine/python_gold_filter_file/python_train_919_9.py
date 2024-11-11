from collections import defaultdict, deque, Counter
from heapq import heappush, heappop, heapify
import math
import bisect
import random
from itertools import permutations, accumulate, combinations, product
import sys
from pprint import pprint
from copy import deepcopy
import string
from bisect import bisect_left, bisect_right
from math import factorial, ceil, floor
from operator import mul
from functools import reduce
from pprint import pprint


sys.setrecursionlimit(2147483647)
INF = 10 ** 15
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
A = LI()
acc = [0] + list(accumulate(A))
plus_acc = [0] + list(accumulate([i if i > 0 else 0 for i in A]))
ans = -INF
for l in range(n - k + 1):
    r = l + k
    ans = max(ans, max(acc[r] - acc[l], 0) + plus_acc[l] + plus_acc[n] - plus_acc[r])

print(ans)