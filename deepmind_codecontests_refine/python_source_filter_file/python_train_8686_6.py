## necessary imports
import sys

input = sys.stdin.readline
from math import log2, log, ceil


# swap_array function
def swaparr(arr, a, b):
    temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp


## gcd function
def gcd(a, b):
    if a == 0:
        return b
    return gcd(b % a, a)


## nCr function efficient using Binomial Cofficient
def nCr(n, k):
    if (k > n - k):
        k = n - k
    res = 1
    for i in range(k):
        res = res * (n - i)
        res = res / (i + 1)
    return res


## upper bound function code -- such that e in a[:i] e < x;
def upper_bound(a, x, lo=0):
    hi = len(a)
    while lo < hi:
        mid = (lo + hi) // 2
        if a[mid] < x:
            lo = mid + 1
        else:
            hi = mid
    return lo


## prime factorization
def primefs(n):
    ## if n == 1    ## calculating primes
    primes = {}
    while (n % 2 == 0):
        primes[2] = primes.get(2, 0) + 1
        n = n // 2
    for i in range(3, int(n ** 0.5) + 2, 2):
        while (n % i == 0):
            primes[i] = primes.get(i, 0) + 1
            n = n // i
    if n > 2:
        primes[n] = primes.get(n, 0) + 1
    ## prime factoriazation of n is stored in dictionary
    ## primes and can be accesed. O(sqrt n)
    return primes


## MODULAR EXPONENTIATION FUNCTION
def power(x, y, p):
    res = 1
    x = x % p
    if (x == 0):
        return 0
    while (y > 0):
        if ((y & 1) == 1):
            res = (res * x) % p
        y = y >> 1
        x = (x * x) % p
    return res


## DISJOINT SET UNINON FUNCTIONS
def swap(a, b):
    temp = a
    a = b
    b = temp
    return a, b


# find function
def find(x, link):
    while (x != link[x]):
        x = link[x]
    return x


# the union function which makes union(x,y)
# of two nodes x and y
def union(x, y, link, size):
    x = find(x, link)
    y = find(y, link)
    if size[x] < size[y]:
        x, y = swap(x, y)
    if x != y:
        size[x] += size[y]
        link[y] = x


## returns an array of boolean if primes or not USING SIEVE OF ERATOSTHANES
def sieve(n):
    prime = [True for i in range(n + 1)]
    p = 2
    while (p * p <= n):
        if (prime[p] == True):
            for i in range(p * p, n + 1, p):
                prime[i] = False
        p += 1
    return prime


#### PRIME FACTORIZATION IN O(log n) using Sieve ####
MAXN = int(1e6 + 5)

'''
def spf_sieve():
    spf[1] = 1;
    for i in range(2, MAXN):
        spf[i] = i;
    for i in range(4, MAXN, 2):
        spf[i] = 2;
    for i in range(3, ceil(MAXN ** 0.5), 2):
        if spf[i] == i:
            for j in range(i * i, MAXN, i):
                if spf[j] == j:
                    spf[j] = i;
    ## function for storing smallest prime factors (spf) in the array

################## un-comment below 2 lines when using factorization #################
# spf = [0 for i in range(MAXN)]
# spf_sieve()
def factoriazation(x):
    ret = {};
    while x != 1:
        ret[spf[x]] = ret.get(spf[x], 0) + 1;
        x = x // spf[x]
    return ret
    ## this function is useful for multiple queries only, o/w use
    ## primefs function above. complexity O(log n)'''
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
input = lambda: sys.stdin.readline().rstrip("\r\n")
##########################################################
from collections import Counter
#for _ in range(int(input())):
n,m=map(int,input().split())
    #arr= list(map(int, input().split()))
f=1
for i in range(n):
    s=list(input())
    for j in range(m):
        if s[j]==".":
            if (i+j)%2==0:
                s[i]="B"
            else:
                s[j]="W"
    print("".join(s))

