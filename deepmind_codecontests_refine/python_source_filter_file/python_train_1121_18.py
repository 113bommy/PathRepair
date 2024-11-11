from collections import defaultdict, deque, Counter
from heapq import heappush, heappop, heapify
import bisect
import random
from itertools import permutations, accumulate, combinations, product
import sys
import string
from bisect import bisect_left, bisect_right
from math import factorial, ceil, floor, acos, asin, atan, sqrt, tan, cos, pi
from operator import mul
from functools import reduce
from pprint import pprint


sys.setrecursionlimit(10 ** 7)
INF = 10 ** 20
def LI(): return list(map(int, sys.stdin.readline().split()))
def I(): return int(sys.stdin.readline())
def LS(): return sys.stdin.readline().split()
def S(): return sys.stdin.readline().strip()
def IR(n): return [I() for i in range(n)]
def LIR(n): return [LI() for i in range(n)]
def SR(n): return [S() for i in range(n)]
def LSR(n): return [LS() for i in range(n)]
def SRL(n): return [list(S()) for i in range(n)]
def MSRL(n): return [[int(j) for j in list(S())] for i in range(n)]
mod = 10 ** 9 + 7


n, m = LI()
hor = []
ver = []
x_co = {-INF, INF}
y_co = {-INF, INF}
for _ in range(n):
    a, b, c = LI()
    x_co.add(a)
    x_co.add(b)
    y_co.add(c)
    ver += [(a, b, c)]

for _ in range(m):
    d, e, f = LI()
    x_co.add(d)
    y_co.add(e)
    y_co.add(f)
    hor += [(d, e, f)]


x_co = sorted(x_co)
y_co = sorted(y_co)
XD = {val:i for i,val in enumerate(x_co)}
YD = {val:i for i,val in enumerate(y_co)}
x_len = len(x_co) * 2 - 1
y_len = len(y_co) * 2 - 1
grid = [[0] * y_len for _ in range(x_len)]
x_range = [0] * x_len
y_range = [0] * y_len
x_range[0] = x_range[-1] = y_range[0] = y_range[-1] = INF
for i in range(len(x_co) - 1):
    x_range[i * 2 + 1] = x_co[i + 1] - x_co[i]
    if x_co[i] <= 0 <= x_co[i + 1]:
        sx = i * 2 + 1

for j in range(len(y_co) - 1):
    y_range[j * 2 + 1] = x_co[j + 1] - y_co[j]
    if y_co[j] <= 0 <= y_co[j + 1]:
        sy = j * 2 + 1

for a, b, c in ver:
    yi = YD[c] * 2
    for xi in range(XD[a] * 2,  XD[b] * 2 + 1):
        grid[xi][yi] = 1


for d, e, f in hor:
    xi = XD[d] * 2
    for yi in range(YD[e] * 2,  YD[f] * 2 + 1):
        grid[xi][yi] = 1


ans = x_range[sx] * y_range[sy]
grid[sx][sy] = 1


ans = 0
dq = deque([(sx, sy)])
grid[sx][sy] = 1
diff = ((0, 1), (1, 0), (-1, 0), (0, -1))
ans += x_range[sx] * y_range[sy]
while dq:
    x, y = dq.popleft()
    for dx, dy in diff:
        nx, ny = dx + x, dy + y
        if grid[nx][ny]:
            continue
        nx += dx;
        ny += dy
        if grid[nx][ny]:
            continue
        grid[nx][ny] = 1
        dq.append((nx, ny))
        ans += x_range[nx] * y_range[ny]
        if ans >= INF:
            print("INF")
            exit()

print(ans)




