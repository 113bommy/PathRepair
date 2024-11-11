# ------------------------template--------------------------#
import os
import sys
import math
import collections
import functools
import itertools

# from fractions import *
import heapq
import bisect
from io import BytesIO, IOBase
from typing import Union


def vsInput():
    sys.stdin = open("input.txt", "r")
    sys.stdout = open("output.txt", "w")


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
input = lambda: sys.stdin.readline().rstrip("\r\n")
ALPHA = "abcde"
MOD = 10 ** 9 + 7
EPS = 1e-6


def Ceil(a, b):
    return a // b + int(a % b > 0)


def INT():
    return int(input())


def STR():
    return input()


def INTS():
    return tuple(map(int, input().split()))


def ARRINT():
    return [int(i) for i in input().split()]


def ARRSTR():
    return [i for i in input().split()]


# -------------------------code---------------------------#
class UnionFind:
    def __init__(self, n):
        self.n = n
        self.parents = [-1] * n
        self.group = n

    def find(self, x):
        if self.parents[x] < 0:
            return x
        else:
            self.parents[x] = self.find(self.parents[x])
            return self.parents[x]

    def union(self, x, y):
        x = self.find(x)
        y = self.find(y)

        if x == y:
            return
        self.group -= 1
        if self.parents[x] > self.parents[y]:
            x, y = y, x

        self.parents[x] += self.parents[y]
        self.parents[y] = x

    def size(self, x):
        return -self.parents[self.find(x)]

    def same(self, x, y):
        return self.find(x) == self.find(y)

    def members(self, x):
        root = self.find(x)
        return [i for i in range(self.n) if self.find(i) == root]

    def roots(self):
        return [i for i, x in enumerate(self.parents) if x < 0]

    def group_count(self):
        return self.group

    def all_group_members(self):
        dic = {r: [] for r in self.roots()}
        for i in range(self.n):
            dic[self.find(i)].append(i)
        return dic

    def __str__(self):
        return "\n".join("{}: {}".format(r, self.members(r)) for r in self.roots())


n, m1, m2 = INTS()

uf1 = UnionFind(n)
uf2 = UnionFind(n)

for _ in range(m1):
    x, y = INTS()
    uf1.union(x - 1, y - 1)

for _ in range(m2):
    x, y = INTS()
    uf2.union(x - 1, y - 1)

res = []
for i in range(n):
    for j in range(i + 1, n):
        if not uf1.same(i, j) and not uf2.same(i, j):
            uf1.union(i, j)
            uf2.union(i, j)
            res += [(i + 1, j + 1)]
print(len(res))
for i in range(len(res)):
    print(*res[i])
