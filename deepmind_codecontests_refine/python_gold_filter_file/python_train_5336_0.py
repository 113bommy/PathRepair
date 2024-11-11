# template by 3xC and starkizard.
# contributors:

#####################################################################################
from __future__ import division, print_function

import sys
import os
from collections import Counter, deque, defaultdict
import itertools
import math
import io

"""Uncomment modules according to your need"""

# from bisect import bisect_left, bisect_right, insort
# from heapq import heappop, heapify, heappush
# from random import randint as rn
# from Queue import Queue as Q
# from copy import deepcopy
# from decimal import *
# import re
# import operator

#####################################################################################
# this enables you to write python3 code with PyPy2 (Python 2)
if sys.version_info[0] < 3:
    input = raw_input
    range = xrange

    filter = itertools.ifilter
    map = itertools.imap
    zip = itertools.izip

#####################################################################################

"""value of mod"""
MOD = 998244353
mod = 10 ** 9 + 7

"""Uncomment next 4 lines if doing huge recursion"""


# import threading
# threading.stack_size(1<<27)
# sys.setrecursionlimit(10000

def prepare_factorial(mod=mod):
    """ returns two lists, factorial and inverse factorial modulo argument by default 10**9 +7 """
    # Comment code out when you don't need inverse factorial or vice versa
    fact = [1]
    for i in range(1, 200005):
        fact.append((fact[-1] * i) % mod)

    ifact = [0] * 200005
    ifact[200004] = pow(fact[200004], mod - 2, mod)
    for i in range(200004, 0, -1):
        ifact[i - 1] = (i * ifact[i]) % mod

    return fact, ifact


def modinv(n, p):
    """ returns N inverse modulo p """
    return pow(n, p - 2, p)


def ncr(n, r, fact, ifact):
    """ takes 4 arguments: n , r and factorial and inverse factorial lists"""
    t = (fact[n] * (ifact[r] * ifact[n - r]) % MOD) % MOD
    return t


def get_n(Sum):
    """this function returns the maximum n for which Summation(n) <= Sum"""
    ans = (-1 + sqrt(1 + 8 * Sum)) // 2
    return ans


def sieve(n):
    """ returns a list of prime numbers till n """
    if n < 2: return list()
    prime = [True for _ in range(n + 1)]
    p = 3
    while p * p <= n:
        if prime[p]:
            for i in range(p * 2, n + 1, p):
                prime[i] = False
        p += 2
    r = [2]
    for p in range(3, n + 1, 2):
        if prime[p]:
            r.append(p)
    return r


def divs(n, start=1):
    """ returns a list of all divisors till n """
    divisors = []
    # rdivisors=[]
    for i in range(start, int(math.sqrt(n) + 1)):
        if n % i == 0:
            if n / i == i:
                divisors.append(i)
            else:
                divisors.extend([i, n // i])
    return divisors


def divn(n, primes):
    """ returns the number of divisors, two arguments n and the sieve till n """
    divs_number = 1
    for i in primes:
        if n == 1:
            return divs_number
        t = 1
        while n % i == 0:
            t += 1
            n //= i
        divs_number *= t


def lrfind(d, x, default=-1):
    """ Takes 2 arguments an iterable and an element. returns a tuple (firstoccurence,lastoccurence) -1 if not found """
    left = right = -1
    for i in range(len(d)):
        if d[i] == x:
            if left == -1: left = i
            right = i
    if left == -1:
        return default, default
    else:
        return left, right


def gcd(x, y):  # math.gcd is slower
    """ returns greatest common divisor of x and y """
    while y:
        x, y = y, x % y
    return x


def check_sorted(a):
    ''' returns True/False '''
    for i in range(len(a) - 1):
        if a[i] > a[i + 1]:
            return False
    return True


def ceil(n, k=1): return n // k + (n % k != 0)  # returns math.ceil but protecting against floating inconsistencies


def input(): return sys.stdin.readline().strip()


def ii(): return int(input())  # inputs integer


def mi(): return map(int, input().split())  # inputting space seperated variables for example x,y,z


def li(): return list(map(int, input().split()))  # inputting a space seperated list of integers


def lw(): return input().split()  # inputting a space seperated list of strings


def lcm(a, b): return abs(a * b) // gcd(a, b)  # returns LCM of two arguments


def prr(a, sep=' ', end='\n'): print(sep.join(map(str, a)),
                                     end=end)  # For printing an iterable with seperator sep as optional second argument (default : " "), ending character (default: "\n") as optional third


def dd(): return defaultdict(int)  # returns a dictionary with values defaulted to 0


def ddl(): return defaultdict(list)  # returns a dictionary with values defaulted to []


def write(s): return sys.stdout.write(s)


###################################################################
def factl(n):
    for i in range(3,int(math.sqrt(n))+1,2):
        if n%i==0:
            return i
    return 1
def main():
    t = ii()
    for _ in range(t):
        n = ii()
        if n%2==0:
            print(n//2,n//2)
        else:
            ans = factl(n)
            #print(ans)
            ma = max(n//ans,ans)
            mi = min(n//ans,ans)
            if mi==1:
                print(1,n-1)
            else:
                print(ma,ma*(mi-1))




# code goes here

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
