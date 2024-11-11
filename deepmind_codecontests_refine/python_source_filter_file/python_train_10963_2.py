from sys import stdout, stdin, setrecursionlimit
from io import BytesIO, IOBase
from collections import *
from itertools import combinations, accumulate, groupby, count
from random import *
from bisect import *
from string import *
from queue import *
from heapq import *
from math import *
from os import *
from re import *

####################################---fast-input-output----#########################################

BUFSIZE = 8192


class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None

    def read(self):
        while True:
            b = read(self._fd, max(fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self):
        while self.newlines == 0:
            b = read(self._fd, max(fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()

    def flush(self):
        if self.writable:
            write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)


class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")


stdin, stdout = IOWrapper(stdin), IOWrapper(stdout)
def input(): return stdin.readline().rstrip("\r\n")
def fast(): return stdin.readline().strip()
def zzz(): return [int(i) for i in fast().split()]


z, zz = input, lambda: list(map(int, z().split()))
szz, graph, mod, szzz = lambda: sorted(
    zz()), {}, 10**9 + 7, lambda: sorted(zzz())


def lcd(xnum1, xnum2): return (xnum1 * xnum2 // gcd(xnum1, xnum2))
def output(answer): stdout.write(str(answer))


dx = [-1, 1, 0, 0, 1, -1, 1, -1]
dy = [0, 0, 1, -1, 1, -1, -1, 1]


###########################---Some Rule For Me To Follow---#################################
"""
	--instants of Reading problem continuously try to understand them.

	--If you Know some , Then you probably don't know him !

"""
###########################---START-CODING---###############################################


# h, w = zzz()
# horizontal = [[0 for _ in range(w)] for _ in range(h)]
# vertical = [[0 for _ in range(w)] for _ in range(h)]
# grids = [list(fast()) for _ in range(h)]

# for i in range(h):
#     for j in range(1, w):
#         horizontal[i][j] = horizontal[i][j - 1] + (grids[i][j] == '.' and grids[i][j - 1] == '.') * 1
# for i in range(1, h):
#     for j in range(w):
#         vertical[i][j] = vertical[i - 1][j] + (grids[i][j] == '.' and grids[i - 1][j] == '.') * 1


# for i in range(int(z())):
#     a, b, c, d = zzz()
#     ans = 0
#     for x in range(a - 1, c):
#         ans += horizontal[x][d - 1] - horizontal[x][b - 1]

#     for x in range(b - 1, d):
#         ans += vertical[c - 1][x] - vertical[a - 1][x]
#     print(ans)

n = int(z())
a = zzz()
b = zzz()

all_sum = sum(a[i] * b[i] for i in range(n))
mx = all_sum
for i in range(1, n):
    newsum = all_sum
    j, k = i + 1, i - 1
    while k >= 0 and j < n:
        newsum -= (a[k] - a[j]) * (b[k] - b[j])
        mx = max(mx, newsum)
        k -= 1
        j += 1
    j, k = i + 1, i
    newsum = all_sum
    while k >= 0 and j < n:
        newsum -= (a[j] - a[k]) * (b[j] - b[k])
        mx = max(mx, newsum)
        k -= 1
        j += 1
print(mx)
