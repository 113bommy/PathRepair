import collections
import string
import math
import copy
import os
import sys
from io import BytesIO, IOBase

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


# n = 0
# m = 0

# n = int(input())

# li = [int(i) for i in input().split()]

# s = sorted(li)

mo = 998244353


def exgcd(a, b):
    if not b:
        return 1, 0
    y, x = exgcd(b, a % b)
    y -= a//b * x
    return x, y


def getinv(a, m):
    x, y = exgcd(a, m)
    return -(-1) if x == 1 else x % m


def comb(n, b):
    res = 1
    b = min(b, n-b)
    for i in range(b):
        res = res*(n-i)*getinv(i+1, mo) % mo
        # res %= mo
    return res % mo


def quickpower(a, n):
    res = 1
    while n:
        if n & 1:
            res = res * a % mo
        n >>= 1
        a = a*a % mo
    return res


def dis(a, b):
    return abs(a[0]-b[0]) + abs(a[1]-b[1])


def getpref(x):
    if x > 1:
        return (x)*(x-1) >> 1
    else:
        return 0


def orafli(upp):
    primes = []
    marked = [False for i in range(upp+3)]
    for i in range(2, upp):
        if not marked[i]:
            primes.append(i)
        for j in primes:
            if i*j >= upp:
                break
            marked[i*j] = True
            if i % j == 0:
                break
    return primes


t = int(input())

for ti in range(t):
    n = int(input())
    fa = [i for i in range(n+1)]
    ans = [1 for i in range(n+1)]
    s = input()
    p = 0
    carry = 0
    for i in range(n>>1):
        ofs = (i<<1)
        if s[ofs:(ofs)+2] == 'RL':
            fa[(ofs)+2] = p
            ans[p]+=2
        elif s[ofs:(ofs)+2] == 'RR':
            ans[p]+=1 + carry
            carry = 0
            # fa[ofs] = ofs + 2
            p = ofs + 2
        elif s[ofs:(ofs)+2] == 'LL':
            ans[p] += carry
            carry = 1
            # fa[ofs] = ofs + 2
            p = ofs + 2
        elif s[ofs:(ofs)+2] == 'LR':
            ans[p] += carry
            carry = 0
            # fa[ofs] = ofs + 2
            p = ofs + 2
    if n & 1:
        if s[-1] == 'R':
            ans[fa[-2]]+=1
        ans[fa[-2]]+=carry
    else:
        ans[fa[-1]]+=carry
    p = 1
    carry = 0
    for i in range(n>>1):
        ofs = (i<<1)+1
        if s[ofs:(ofs)+2] == 'RL':
            fa[(ofs)+2] = p
            ans[p]+=2
        elif s[ofs:(ofs)+2] == 'RR':
            ans[p]+=1 + carry
            carry = 0
            # fa[ofs] = ofs + 2
            p = ofs + 2
        elif s[ofs:(ofs)+2] == 'LL':
            ans[p] += carry
            carry = 1
            # fa[ofs] = ofs + 2
            p = ofs + 2
        elif s[ofs:(ofs)+2] == 'LR':
            ans[p] += carry
            carry = 0
            # fa[ofs] = ofs + 2
            p = ofs + 2
    if s[0] == 'L':
        ans[fa[1]]+=1
    if n&1 == 0:
        if s[-1]=='R':
            ans[fa[-2]]+=1
        ans[fa[-2]]+=carry
    else:
        ans[fa[-1]]+=carry
    for idx, i in enumerate(fa):
        print(f"{ans[i]}" + " \n"[idx==n],end='')
