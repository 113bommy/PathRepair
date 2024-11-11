# pylint: disable=unused-variable
# pylint: enable=too-many-lines
# * Just believe in yourself


# @ Author @CAP
# import numpy
import os
import sys
from io import BytesIO, IOBase
import math as M
import itertools as ITR
from collections import defaultdict as D
from collections import Counter as C
from collections import deque as Q
import threading
from functools import lru_cache, reduce
from functools import cmp_to_key as CMP
from bisect import bisect_left as BL
from bisect import bisect_right as BR
import random as R
import string
import cmath, time

enum = enumerate
start_time = time.time()

# * Variables

MOD = 1_00_00_00_007
MA = float("inf")
MI = float("-inf")

# * Graph 8 direction
di8 = ((1, 0), (1, 1), (0, 1), (-1, 1), (-1, 0), (-1, -1), (0, -1), (1, -1))

# * Graph 4 direction
di4 = ((1, 0), (0, 1), (-1, 0), (0, -1))

# * Stack increment


def increase_stack():
    sys.setrecursionlimit(2 ** 32 // 2 - 1)
    threading.stack_size(1 << 27)
    # sys.setrecursionlimit(10**6)
    # threading.stack_size(10**8)
    # t = threading.Thread(target=main)
    # t.start()
    # t.join()


# * Region Funtions


def binary(n):
    return bin(n)[2:]


def decimal(s):
    return int(s, 2)


def pow2(n):
    p = 0
    while n > 1:
        n //= 2
        p += 1
    return p


def maxfactor(n):
    q = []
    for i in range(1, int(n ** 0.5) + 1):
        if n % i == 0:
            q.append(i)
    if q:
        return q[-1]


def factors(n):
    q = []
    for i in range(1, int(n ** 0.5) + 1):
        if n % i == 0:
            q.append(i)
            q.append(n // i)
    return list(sorted(list(set(q))))


def primeFactors(n):
    l = []
    while n % 2 == 0:
        l.append(2)
        n = n / 2
    for i in range(3, int(M.sqrt(n)) + 1, 2):
        while n % i == 0:
            l.append(i)
            n = n / i
    if n > 2:
        l.append(int(n))
    l.sort()
    return l


def isPrime(n):
    if n == 1:
        return False
    else:
        root = int(n ** 0.5)
        root += 1
        for i in range(2, root):
            if n % i == 0:
                return False
        return True


def seive(n):
    a = []
    prime = [True for i in range(n + 1)]
    p = 2
    while p * p <= n:
        if prime[p] == True:
            for i in range(p ** 2, n + 1, p):
                prime[i] = False
        p = p + 1
    for p in range(2, n + 1):
        if prime[p]:
            a.append(p)
    prime[0] = prime[1] = False
    return a, prime


def maxPrimeFactors(n):
    maxPrime = -1
    while n % 2 == 0:
        maxPrime = 2
        n >>= 1
    for i in range(3, int(M.sqrt(n)) + 1, 2):
        while n % i == 0:
            maxPrime = i
            n = n / i
    if n > 2:
        maxPrime = n
    return int(maxPrime)


def countchar(s, i):
    c = 0
    ch = s[i]
    for i in range(i, len(s)):
        if s[i] == ch:
            c += 1
        else:
            break
    return c


def str_counter(a):
    q = [0] * 26
    for i in range(len(a)):
        q[ord(a[i]) - 97] = q[ord(a[i]) - 97] + 1
    return q


def lis(arr):
    n = len(arr)
    lis = [1] * n
    maximum = 0

    for i in range(1, n):
        for j in range(0, i):
            if arr[i] > arr[j] and lis[i] < lis[j] + 1:
                lis[i] = lis[j] + 1
                maximum = max(maximum, lis[i])
    return maximum


def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)


def agcd(a, *b):

    for i in b:
        a = gcd(a, i)
    return a


def lcm(a, *b):
    val = a
    gc = a
    for i in b:
        gc = gcd(gc, i)
        val *= i
    return val // gc


def ncr(n, r):
    return M.factorial(n) // (M.factorial(n - r) * M.factorial(r))


def npr(n, r):
    return M.factorial(n) // M.factorial(n - r)


# * Make work easy funtions


def IF(c, t, f):
    return t if c else f


def YES(c):
    print(IF(c, "YES", "NO"))


def Yes(c):
    print(IF(c, "Yes", "No"))


def yes(c):
    print(IF(c, "yes", "no"))


def JA(a, sep=" "):
    print(sep.join(map(str, a)))


def JAA(a, s="\n", t=" "):
    return s.join(t.join(map(str, b)) for b in a)


def PS(a, s=" "):
    print(str(a), end=s)


# * Region Taking Input


def I():
    return int(inp())


def F():
    return float(inp())


def LI():
    return list(map(int, inp().split()))


def LF():
    return list(map(float, inp().split()))


def MATI(n):
    return [LI() for i in range(n)]


def MATS(n):
    return [list(inp()) for i in range(n)]


def IV():
    return map(int, inp().split())


def FV():
    return map(float, inp().split())


def LS():
    return list(inp())


def S():
    return inp()


# * Region Fastio

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
inp = lambda: sys.stdin.readline().rstrip("\r\n")


# >==================================== Write The Useful Code Here ============================

# >Make it one if there is some test cases
TestCases = 0  # >=====================
# > =======================================
"""
> Sometimes later becomes never. Do it now.
! Be Better than yesterday.
!Your limitation—it’s only your imagination.
> Push yourself, because no one else is going to do it for you.
? The harder you work for something, the greater you’ll feel when you achieve it.
! Great things never come from comfort zones.
! Don’t stop when you’re tired. Stop when you’re done.
> Do something today that your future self will thank you for.
? It’s going to be hard, but hard does not mean impossible.
! Sometimes we’re tested not to show our weaknesses, but to discover our strengths.
"""
# @  Goal is to get Candidate Master


def solve():
    x, y, z = IV()
    a = ((y * z) / x) ** 0.5
    b = ((x * z) / y) ** 0.5
    c = ((x * y) / z) ** 0.5
    print(4 * (a + b + c))


# ! This is the Main Function


def main():
    flag = 1
    #! Checking we are offline or not
    try:
        sys.stdin = open(
            "c:/Users/Manoj Chowdary/Documents/python/CodeForces/contest-div-2/input.txt",
            "r",
        )
        sys.stdout = open(
            "c:/Users/Manoj Chowdary/Documents/python/CodeForces/contest-div-2/output.txt",
            "w",
        )
    except:
        flag = 0

    t = 1
    if TestCases:
        t = I()
    for _ in range(1, t + 1):
        solve()

    if flag:
        print("Time: %.4f sec" % (time.time() - start_time))
        localtime = time.asctime(time.localtime(time.time()))
        print(localtime)
        sys.stdout.close()


# !  End Region


if __name__ == "__main__":

    # ? Incresing Stack Limit
    # increase_stack()

    #! Calling Main Function
    main()