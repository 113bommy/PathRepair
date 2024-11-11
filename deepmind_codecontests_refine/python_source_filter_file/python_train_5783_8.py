# ===============================================================================================
# importing some useful libraries.
from __future__ import division, print_function
from fractions import Fraction
import sys
import os
from io import BytesIO, IOBase
from itertools import *
import bisect
from heapq import *
from math import ceil, floor
from copy import *
from collections import deque, defaultdict
from collections import Counter as counter  # Counter(list)  return a dict with {key: count}
from itertools import combinations  # if a = [1,2,3] then print(list(comb(a,2))) -----> [(1, 2), (1, 3), (2, 3)]
from itertools import permutations as permutate
from bisect import bisect_left as bl
from operator import *
# If the element is already present in the list,

# the left most position where element has to be inserted is returned.
from bisect import bisect_right as br
from bisect import bisect

# If the element is already present in the list,
# the right most position where element has to be inserted is returned

# ==============================================================================================
# fast I/O region

BUFSIZE = 8192
from sys import stderr


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

# ===============================================================================================
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

# ===============================================================================================
# some shortcuts

mod = 1000000007


def inp(): return sys.stdin.readline().rstrip("\r\n")  # for fast input


def out(var): sys.stdout.write(str(var))  # for fast output, always take string


def lis(): return list(map(int, inp().split()))


def stringlis(): return list(map(str, inp().split()))


def sep(): return map(int, inp().split())


def strsep(): return map(str, inp().split())


def fsep(): return map(float, inp().split())


def nextline(): out("\n")  # as stdout.write always print sring.


def testcase(t):
    for p in range(t):
        solve()


def pow(x, y, p):
    res = 1  # Initialize result
    x = x % p  # Update x if it is more , than or equal to p
    if (x == 0):
        return 0
    while (y > 0):
        if ((y & 1) == 1):  # If y is odd, multiply, x with result
            res = (res * x) % p

        y = y >> 1  # y = y/2
        x = (x * x) % p
    return res


from functools import reduce


def factors(n):
    return set(reduce(list.__add__,
                      ([i, n // i] for i in range(1, int(n ** 0.5) + 1) if n % i == 0)))


def gcd(a, b):
    if a == b: return a
    while b > 0: a, b = b, a % b
    return a


# N=100000
# mod = 10**9 +7
# fac = [1, 1]
# finv = [1, 1]
# inv = [0, 1]
#
# for i in range(2, N + 1):
#     fac.append((fac[-1] * i) % mod)
#     inv.append(mod - (inv[mod % i] * (mod // i) % mod))
#     finv.append(finv[-1] * inv[-1] % mod)
#
#
# def comb(n, r):
#     if n < r:
#         return 0
#     else:
#         return fac[n] * (finv[r] * finv[n - r] % mod) % mod


##############Find sum of product of subsets of size k in a array
# ar=[0,1,2,3]
# k=3
# n=len(ar)-1
# dp=[0]*(n+1)
# dp[0]=1
# for pos in range(1,n+1):
#     dp[pos]=0
#     l=max(1,k+pos-n-1)
#     for j in range(min(pos,k),l-1,-1):
#         dp[j]=dp[j]+ar[pos]*dp[j-1]
# print(dp[k])

def prefix_sum(ar):  # [1,2,3,4]->[1,3,6,10]
    return list(accumulate(ar))


def suffix_sum(ar):  # [1,2,3,4]->[10,9,7,4]
    return list(accumulate(ar[::-1]))[::-1]

def lcm(a,b):
    return (a*b)//gcd(a,b)

# =========================================================================================
from collections import defaultdict


def numberOfSetBits(i):
    i = i - ((i >> 1) & 0x55555555)
    i = (i & 0x33333333) + ((i >> 2) & 0x33333333)
    return (((i + (i >> 4) & 0xF0F0F0F) * 0x1010101) & 0xffffffff) >> 24


def N():
    return int(inp())

def solve():
    n,a,b,p,q=sep()
    ans=0
    ans+=(p*(n//a) + q*(n//b))
    m=min(p,q)
    ans-=(m*(n//(a*b)))
    print(ans)





















solve()
#testcase(int(inp()))


