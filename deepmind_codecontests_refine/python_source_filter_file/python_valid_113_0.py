import os
import sys
from io import BytesIO, IOBase
import math as mt
import itertools as it
import operator as op
import bisect as bs
import heapq as hp
from functools import reduce
from io import BytesIO, IOBase
from collections import deque, defaultdict, OrderedDict, Counter, ChainMap, _chain
maxx, localsys, mod = 1 << 60, 0, int(1e9 + 7)
def nCr(n, r): return reduce(op.mul, range(n - r + 1, n + 1), 1) // mt.factorial(r)

def ceil(a, b): return (a + b - 1) // b

def lcm(a, b): return a * b // mt.gcd(a, b)


gcdm = lambda *args: reduce(mt.gcd, args, 0)

def lcm(a, b): return a * b // mt.gcd(a, b)


lcmm = lambda *args: reduce(lcm, args, 1)

_str = str
str = lambda x=b"": x if type(x) is bytes else _str(x).encode()

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
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()

    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)


class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")


sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
def input(): return sys.stdin.readline().rstrip("\r\n")

# end region


def maps(): return map(int, input().split())

#   THINK ABOUT THE EDGE CASES ..........

#   DON'T SUBMIT UNLESS YOU ARE ABSOLUTELY SURE !!!!!


INF = 10**18
import sys
import pprint
import logging
from logging import getLogger
import array

# sys.setrecursionlimit(10 ** 9)

def input(): return sys.stdin.readline().rstrip("\r\n")

def maps(): return [int(i) for i in input().split()]


logging.basicConfig(
    format="%(message)s",
    level=logging.WARNING,
)
logger = getLogger(__name__)
logger.setLevel(logging.INFO)


def debug(msg, *args):
    logger.info(f'{msg}={pprint.pformat(args)}')


# lOOKOUT FOR THE EDGE CASES

def search(arr, key):
    l, h = 0, len(arr) - 1
    idx = n - 1
    while l <= h:
        m = (l + h) >> 1
        if arr[m][0] <= key:
            l = m + 1
        else:
            idx = m
            h = m - 1
        return idx


from itertools import accumulate
n, = maps()
a = [*maps()]
m, = maps()
arr = [[*maps()] for _ in range(m)]
tot = sum(a)
A = []  # (defense , attack)
a.sort()
for i in range(n):
    A.append((tot - a[i], a[i]))
A.sort(key=lambda x: (x[0], x[1]))
# print(A)
# print(search(A, 9))
ans = [0] * m
ii = 0
for defense, attack in arr:
    idx = search(A, attack)
    # dragon's attack <= A[idx][0] and dragon's defense <= A[idx][1]
    if attack <= A[idx][0] and defense <= A[idx][1]:
        ans[ii] = 0
    else:
        mx = defense + attack
        t1, t2, t3 = 0, 0, 0
        if attack > A[idx][0]:
            t1 += attack - A[idx][0]
        if defense > A[idx][1]:
            t1 += defense - A[idx][1]

        if idx - 1 >= 0:
            if attack > A[idx - 1][0]:
                t2 += attack - A[idx - 1][0]
            if defense > A[idx - 1][1]:
                t2 += defense - A[idx - 1][1]
        else:
            t2 = INF

        if idx + 1 < n:
            if attack > A[idx + 1][0]:
                t3 += attack - A[idx + 1][0]
            if defense > A[idx + 1][1]:
                t3 += defense - A[idx + 1][1]
        else:
            t3 = INF
        mx = min(mx, t3, t2, t1)
        ans[ii] = mx

    ii += 1
print(*ans, sep='\n')
