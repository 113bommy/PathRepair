from itertools import combinations, accumulate, groupby, count
from sys import stdout, stdin, setrecursionlimit
from io import BytesIO, IOBase
from collections import *
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
def fast(): return stdin.readline().strip()
def zzz(): return [int(i) for i in fast().split()]


z, zz = input, lambda: list(map(int, z().split()))
szz, graph, mod, szzz = lambda: sorted(
    zz()), {}, 10**9 + 7, lambda: sorted(zzz())


def lcd(xnum1, xnum2): return (xnum1 * xnum2 // gcd(xnum1, xnum2))
def print(answer, end=''): stdout.write(str(answer) + end)


dx = [-1, 1, 0, 0, 1, -1, 1, -1]
dy = [0, 0, 1, -1, 1, -1, -1, 1]


###########################---Some Rule For Me To Follow---#################################
"""
    --instants of Reading problem continuously try to understand them.

    --If you Know some , Then you probably don't know him !

"""
###########################---START-CODING---###############################################


# num = int(z())
# lst = []

# for _ in range(num):
#     arr = zzz()
#     lst.append(arr)

# left = 0
# right = 10**9 + 1

# while right - left > 1:
#     curr = (right + left) // 2
#     currSet = set()
#     for i in range(num):
#         msk = 0
#         for j in range(5):
#             if lst[i][j] >= curr:
#                 msk |= 1 << j
#         currSet.add(msk)

#     flag = False

#     for x in currSet:
#         for y in currSet:
#             for k in currSet:
#                 if x | y | k == 31:
#                     flag = True
#     if flag:
#         left = curr
#     else:
#         right = curr
# print(left)

n, m = zzz()
arr = zzz()

new = [0] * (n + 1)

for i in range(n - 2, -1, -1):
    if arr[i] == arr[i + 1]:
        new[i] = new[i + 1]
    else:
        new[i] = i + 1

res = [0] * (m)
for _ in range(m):
    l, r, x = zzz()
    ans = -1
    if arr[l - 1] != x:
        ans = l
    else:
        if new[l - 1] != new[r - 1]:
            ans = new[l - 1] + 1
    res[_] = ans


for i in res:
    print(i)
