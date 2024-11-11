"""Template for Python Competitive Programmers prepared by pajengod and   many others """
#  ////////// SHUBHAM SHARMA \\\\\\\\\\\\\
# to use the print and division function of Python3
from __future__ import division, print_function

"""value of mod"""
MOD = 998244353
mod = 10 ** 9 + 7

"""use resource"""
# import resource
# resource.setrlimit(resource.RLIMIT_STACK, [0x100000000, resource.RLIM_INFINITY])

"""for factorial"""


def prepare_factorial():
    fact = [1]
    for i in range(1, 100005):
        fact.append((fact[-1] * i) % mod)
    ifact = [0] * 100005
    ifact[100004] = pow(fact[100004], mod - 2, mod)
    for i in range(100004, 0, -1):
        ifact[i - 1] = (i * ifact[i]) % mod
    return fact, ifact


"""uncomment next 4 lines while doing recursion based question"""
# import threading
# threading.stack_size(1<<27)
import sys

# sys.setrecursionlimit(10000)


"""uncomment modules according to your need"""
from bisect import bisect_left, bisect_right, insort
# from itertools import repeat
from math import floor, ceil, sqrt, degrees, atan, pi, log, sin, radians
from heapq import heappop, heapify, heappush
# from random import randint as rn
# from Queue import Queue as Q
from collections import Counter, defaultdict, deque


# from copy import deepcopy
# from decimal import *
# import re
# import operator


def modinv(n, p):
    return pow(n, p - 2, p)


def ncr(n, r, fact, ifact):  # for using this uncomment the lines calculating fact and ifact
    t = (fact[n] * (ifact[r] * ifact[n - r]) % mod) % mod
    return t


def intarray(): return map(int, sys.stdin.readline().strip().split())


def array(): return list(map(int, sys.stdin.readline().strip().split()))


def input(): return sys.stdin.readline().strip()


"""*****************************************************************************************"""


def GCD(x, y):
    while y:
        x, y = y, x % y
    return x


def lcm(x, y):
    return (x * y) // (GCD(x, y))


def get_xor(n):
    return [n, 1, n + 1, 0][n % 4]


def fast_expo(a, b):
    res = 1
    while b:
        if b & 1:
            res = (res * a)
            res %= MOD
            b -= 1
        else:
            a = (a * a)
            a %= MOD
            b >>= 1
    res %= MOD
    return res


def get_n(P):  # this function returns the maximum n for which Summation(n) <= Sum

    ans = (-1 + sqrt(1 + 8 * P)) // 2
    return ans


""" ********************************************************************************************* """
"""
 array() # for araay
 intarray() # for map array
 SAMPLE INPUT HERE
5
2
01
10
5
01011
11100
2
01
01
10
0110011011
1000110100
1
0
1



"""
""" OM SAI RAM """
def reverse(a,r):
    l =0
    #print(''.join(a),r)
    if r&1==0:
        if a[r//2]=='0':
            a[r//2]='1'
        else:
            a[r//2]='0'
    while(l<r):
        a[l],a[r] = a[r],a[l]
        if a[l]=='0':
            a[l]='1'
        elif a[l]=='1':
            a[l]='0'
        if a[r]=='0':
            a[r]='1'
        elif a[r]=='1':
            a[r]='0'
        l+=1
        r-=1
    #print(''.join(a))
    return a

def solve():
    n = int(input())
    a= list(input())
    b= list(input())
    out = []
    for i in range(n-1,-1,-1):
        if b[i]==a[i]:
            continue
        else:
            if b[i]!=a[0]:
                out.append(i)
                a = reverse(a, i)
            else:
                out.append(0)
                if a[0]=='1':
                    a[0]='0'
                else:
                    a[0]='1'
                out.append(i)
                a = reverse(a,i)
    print(len(out),*out)
    #print(''.join(a),''.join(b))
    return

def main():
    T = int(input())
    while T:
        solve()
        T -= 1


"""OM SAI RAM """


""" -------- Python 2 and 3 footer by Pajenegod and c1729 ---------"""

py2 = round(0.5)
if py2:
    from future_builtins import ascii, filter, hex, map, oct, zip

    range = xrange

import os, sys
from io import IOBase, BytesIO

BUFSIZE = 8192


class FastIO(BytesIO):
    newlines = 0

    def __init__(self, file):
        self._file = file
        self._fd = file.fileno()
        self.writable = "x" in file.mode or "w" in file.mode
        self.write = super(FastIO, self).write if self.writable else None

    def _fill(self):
        s = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
        self.seek((self.tell(), self.seek(0, 2), super(FastIO, self).write(s))[0])
        return s

    def read(self):
        while self._fill(): pass
        return super(FastIO, self).read()

    def readline(self):
        while self.newlines == 0:
            s = self._fill();
            self.newlines = s.count(b"\n") + (not s)
        self.newlines -= 1
        return super(FastIO, self).readline()

    def flush(self):
        if self.writable:
            os.write(self._fd, self.getvalue())
            self.truncate(0), self.seek(0)


class IOWrapper(IOBase):

    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        if py2:
            self.write = self.buffer.write
            self.read = self.buffer.read
            self.readline = self.buffer.readline
        else:
            self.write = lambda s: self.buffer.write(s.encode('ascii'))
            self.read = lambda: self.buffer.read().decode('ascii')
            self.readline = lambda: self.buffer.readline().decode('ascii')


sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip('\r\n')

# sys.stdin = open('input.txt', 'r')
# sys.stdout = open('output.txt', 'w')

""" main function"""

if __name__ == '__main__':
    main()
    # threading.Thread(target=main).start()