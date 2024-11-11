"""
from sys import stdin, stdout
import math
from functools import reduce
import statistics
import numpy as np
import itertools
import operator
from sys import stdin, stdout
import math
from functools import reduce
import statistics
import numpy as np
import itertools
import sys
import operator
from collections import Counter
import decimal
sys.setrecursionlimit(10 ** 6 + 1)
"""
# from time import time
import os
import sys
import math
from io import BytesIO, IOBase
# from collections import *
# from bisect import *
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

# def lcm(a, b):
#     return (a * b) // math.gcd(a, b)
#
# def HAHA(n):
#     if n == 1:
#         return 0
#     elif n == 2:
#         return 1
#     elif n % 2 == 0:
#         return 0
#     else:
#         i = 3
#         while(i * i <= n):
#             if(n % i == 0):
#                 return 0
#             i += 2
#         return 1
def check(x, s):
    cnt = 0
    xx = list(x)
    ss = list(s)
    ind = 0
    for a in range(len(ss)):
        if ind >= len(xx):
            cnt += len(ss) - a
            break
        else:
            if ss[a] != xx[ind]:
                cnt += 1
            else:
                ind += 1
    cnt += len(xx) - ind

    return cnt

l = [str(2 ** x) for x in range(80)]

def prog_name():
    n = int(input())
    if n & (n - 1) == 0:
        print(0)
    else:
        s = str(n)
        m = 1000000
        for x in l:
            m = min(m, check(x, s))
        print(m)



    # print()
def main ():
    # init = time()
    T = int(input())
    for unique in range(T):
        # print("Case #"+str(unique+1)+":",end = " ")
        prog_name()
    # print(time() - init)


if __name__ == "__main__":
    main()