"""
    Satwik_Tiwari ;) .
    25 june , 2020  - Thursday
"""

#===============================================================================================
#importing some useful libraries.
from __future__ import division, print_function

from fractions import Fraction
import sys
import os
from io import BytesIO, IOBase


import bisect
from heapq import *
from math import *
from collections import deque
from collections import Counter as counter  # Counter(list)  return a dict with {key: count}
from itertools import combinations as comb # if a = [1,2,3] then print(list(comb(a,2))) -----> [(1, 2), (1, 3), (2, 3)]
from itertools import permutations as permutate
from bisect import bisect_left as bl
#If the element is already present in the list,
# the left most position where element has to be inserted is returned.
from bisect import bisect_right as br
from bisect import bisect
#If the element is already present in the list,
# the right most position where element has to be inserted is returned

#==============================================================================================

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
#some shortcuts

mod = 1000000007
def inp(): return sys.stdin.readline().rstrip("\r\n") #for fast input
def out(var): sys.stdout.write(str(var))  #for fast output, always take string
def lis(): return list(map(int, inp().split()))
def stringlis(): return list(map(str, inp().split()))
def sep(): return map(int, inp().split())
def strsep(): return map(str, inp().split())
def graph(vertex): return [[] for i in range(0,vertex+1)]
def zerolist(n): return [0]*n
def nextline(): out("\n")  #as stdout.write always print sring.
def testcase(t):
    for p in range(t):
        solve()
def printlist(a) :
    for p in range(0,len(a)):
        out(str(a[p]) + ' ')
def lcm(a,b): return (a*b)//gcd(a,b)
def power(a,b):
    ans = 1
    while(b>0):
        if(b%2==1):
            ans*=a
        a*=a
        b//=2
    return ans
def ncr(n,r): return factorial(n)//(factorial(r)*factorial(max(n-r,1)))
def isPrime(n) : # Check Prime Number or not
    if (n <= 1) : return False
    if (n <= 3) : return True
    if (n % 2 == 0 or n % 3 == 0) : return False
    i = 5
    while(i * i <= n) :
        if (n % i == 0 or n % (i + 2) == 0) :
            return False
        i = i + 6
    return True

#===============================================================================================
# code here ;))
def bs(a,l,h,x):
    while(l<h):
        # print(l,h)
        mid = (l+h)//2
        if(a[mid] == x):
            return mid
        if(a[mid] < x):
            l = mid+1
        else:
            h = mid
    return l

def sieve(a): #O(n loglogn) nearly linear
    #all odd mark 1
    for i in range(3,((10**6)+1),2):
        a[i] = 1
    #marking multiples of i form i*i 0. they are nt prime
    for i in range(3,((10**6)+1),2):
        for j in range(i*i,((10**6)+1),i):
            a[j] = 0
    a[2] = 1 #special left case
    return (a)


def solve():
    n  = int(inp())
    a = lis()
    a = sorted(a)
    print(a)
    cnt = [0]*(150002)
    for i in range(0,n):
        if(a[i]==1):
            if(cnt[1] == 0):
                cnt[1]+=1
            elif(cnt[2]==0):
                cnt[2] +=1

        else:
            if(cnt[a[i]-1]==0):
                cnt[a[i]-1] +=1
            elif(cnt[a[i]] == 0):
                cnt[a[i]] +=1
            elif(cnt[a[i]+1] == 0):
                cnt[a[i]+1] +=1

        # print(cnt[:12],a[i])

    ans =0
    for i in range(1,150002):
        if(cnt[i] > 0):
            ans+=1
    print(ans)



testcase(1)
# testcase(int(inp()))
