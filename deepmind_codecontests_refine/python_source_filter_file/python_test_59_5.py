"""
from functools import reduce
import statistics
import numpy as np
import itertools
import statistics
import decimal
sys.setrecursionlimit(10 ** 6 + 1)
MAX = sys.maxsize
"""
import operator
import bisect
import math
from queue import PriorityQueue as pq
from heapq import heapify, heappop, heappush, heappushpop, nlargest, heapreplace, nsmallest
from itertools import permutations, accumulate
# from time import time
# import math
import os
import array
import sys
# from math import *
from io import BytesIO, IOBase
from collections import Counter, deque, OrderedDict, defaultdict
from bisect import bisect_right, insort_right
BUFSIZE = 8192
# import array




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
getint = lambda: int(sys.stdin.readline().rstrip("\r\n"))
getints = lambda: map(int, sys.stdin.readline().rstrip("\r\n").split())
li = lambda: list(map(int, sys.stdin.readline().rstrip("\r\n").split()))
getstrs = lambda: map(str, sys.stdin.readline().rstrip("\r\n").split())
ls = lambda: list(map(str, sys.stdin.readline().rstrip("\r\n").split()))



# d is a dictionary min val of d is
# d = { 1 : 2, 4 : 5, 3 : 0}
# min(d.values())
# max(d.values()) = d.most_common(1)[0][1]
# ans = 0

# def gcd(a, b):
#     if a == 0:
#         return b
#     else:
#         return gcd(b % a, a)

# def fact(num):
#     cnt = 0
#     for x in range(1, int(math.sqrt(num)) + 1):
#         if num % x == 0:
#             cnt = x
#             # if num // x == x:
#                 # cnt += 1
#             # else:
#                 # cnt += 2
#     return cnt

# def isPrime(num):
#     if num == 2:
#         return True
#     elif num % 2 == 0:
#         return False
#     else:
#         i = 3
#         while i * i <= num:
#             if num % i == 0:
#                 return False
#             i += 2
#         return True

# def power(x, y):
#     res = 1
#     x = x
#     while y > 0:
#         if y & 1:
#             res = res * x
#         x = x * x
#         y = y >> 1
#     return res


def prog_name():
    n = getint()
    d = {1: [], 2: [], 3: [], 4: [], 5: []}
    for x in range(n):
        temp = li()
        for y in range(5):
            if temp[y] == 1:
                d[y + 1].append(x + 1)

    for a in d:
        if len(d[a]) >= n // 2:
            for b in d:
                if len(d[b]) > n // 2:
                    if a != b:
                        if len(set(d[a]).union(set(d[b]))) == n:
                            print("YES")
                            return
    print("NO")




    # print()
def main ():
    # init = time()
    # T = getint()
    T = getint()
    for unique in range(T):
        # print("Case #"+str(unique+1)+":", end = " ")
        # print()
        prog_name()
    # print(time() - init)


if __name__ == "__main__":
    main()