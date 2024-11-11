"""
    Author - Satwik Tiwari .
    19th Jan , 2021  - Tuesday
"""

#===============================================================================================
#importing some useful libraries.

from __future__ import division, print_function
# from fractions import Fraction
import sys
import os
from io import BytesIO, IOBase

# from itertools import *
from heapq import *
from math import gcd, factorial,floor,ceil,sqrt,log2

from copy import deepcopy
from collections import deque


from bisect import bisect_left as bl
from bisect import bisect_right as br
from bisect import bisect

#==============================================================================================
#fast I/O region
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


def print(*args, **kwargs):
    """Prints the values to a stream, or to sys.stdout by default."""
    sep, file = kwargs.pop("sep", " "), kwargs.pop("file", sys.stdout)
    at_start = True
    for x in args:
        if not at_start:
            file.write(sep)
        file.write(str(x))
        at_start = False
    file.write(kwargs.pop("end", "\n"))
    if kwargs.pop("flush", False):
        file.flush()


if sys.version_info[0] < 3:
    sys.stdin, sys.stdout = FastIO(sys.stdin), FastIO(sys.stdout)
else:
    sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)

# inp = lambda: sys.stdin.readline().rstrip("\r\n")

#===============================================================================================
### START ITERATE RECURSION ###
from types import GeneratorType
def iterative(f, stack=[]):
  def wrapped_func(*args, **kwargs):
    if stack: return f(*args, **kwargs)
    to = f(*args, **kwargs)
    while True:
      if type(to) is GeneratorType:
        stack.append(to)
        to = next(to)
        continue
      stack.pop()
      if not stack: break
      to = stack[-1].send(to)
    return to
  return wrapped_func
#### END ITERATE RECURSION ####

#===============================================================================================
#some shortcuts

def inp(): return sys.stdin.readline().rstrip("\r\n") #for fast input
def out(var): sys.stdout.write(str(var))  #for fast output, always take string
def lis(): return list(map(int, inp().split()))
def stringlis(): return list(map(str, inp().split()))
def sep(): return map(int, inp().split())
def strsep(): return map(str, inp().split())
# def graph(vertex): return [[] for i in range(0,vertex+1)]
def testcase(t):
    for pp in range(t):
        solve(pp)
def google(p):
    print('Case #'+str(p)+': ',end='')
def lcm(a,b): return (a*b)//gcd(a,b)
def power(x, y, p) :
    y%=(p-1)  #not so sure about this. used when y>p-1. if p is prime.
    res = 1     # Initialize result
    x = x % p  # Update x if it is more , than or equal to p
    if (x == 0) :
        return 0
    while (y > 0) :
        if ((y & 1) == 1) : # If y is odd, multiply, x with result
            res = (res * x) % p

        y = y >> 1      # y = y/2
        x = (x * x) % p
    return res
def ncr(n,r): return factorial(n) // (factorial(r) * factorial(max(n - r, 1)))
def isPrime(n) :
    if (n <= 1) : return False
    if (n <= 3) : return True
    if (n % 2 == 0 or n % 3 == 0) : return False
    i = 5
    while(i * i <= n) :
        if (n % i == 0 or n % (i + 2) == 0) :
            return False
        i = i + 6
    return True
inf = pow(10,21)
mod = 10**9+7
#===============================================================================================
# code here ;))

def bucketsort(order, seq):
    buckets = [0] * (max(seq) + 1)
    for x in seq:
        buckets[x] += 1
    for i in range(len(buckets) - 1):
        buckets[i + 1] += buckets[i]

    new_order = [-1] * len(seq)
    for i in reversed(order):
        x = seq[i]
        idx = buckets[x] = buckets[x] - 1
        new_order[idx] = i

    return new_order


def ordersort(order, seq, reverse=False):
    bit = max(seq).bit_length() >> 1
    mask = (1 << bit) - 1
    order = bucketsort(order, [x & mask for x in seq])
    order = bucketsort(order, [x >> bit for x in seq])
    if reverse:
        order.reverse()
    return order


def long_ordersort(order, seq):
    order = ordersort(order, [int(i & 0x7fffffff) for i in seq])
    return ordersort(order, [int(i >> 31) for i in seq])


def multikey_ordersort(order, *seqs, sort=ordersort):
    for i in reversed(range(len(seqs))):
        order = sort(order, seqs[i])
    return order

class DisjointSetUnion:
    def __init__(self, n):
        self.parent = list(range(n))
        self.size = [1] * n
        self.num_sets = n

    def find(self, a):
        acopy = a
        while a != self.parent[a]:
            a = self.parent[a]
        while acopy != a:
            self.parent[acopy], acopy = a, self.parent[acopy]
        return a

    def union(self, a, b):
        a, b = self.find(a), self.find(b)
        if a != b:
            if self.size[a] < self.size[b]:
                a, b = b, a

            self.num_sets -= 1
            self.parent[b] = a
            self.size[a] += self.size[b]

    def set_size(self, a):
        return self.size[self.find(a)]

    def __len__(self):
        return self.num_sets



def solve(case):
    n = int(inp())
    a = []
    for i in range(n):
        a.append(inp())

    ans = 6
    for i in range(n):
        for j in range(n):
            if(i == j):
                continue
            cnt = 0
            for k in range(len(a[i])):
                if(a[i][k] != a[j][k]):
                    cnt+=1
            ans = min(ans,cnt//2-1 if cnt%2==0 else cnt//2)

    print(ans)


testcase(1)
# testcase(int(inp()))





