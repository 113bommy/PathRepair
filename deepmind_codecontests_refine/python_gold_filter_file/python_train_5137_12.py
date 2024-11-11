
import bisect
from itertools import accumulate
import os
import sys
import math
from decimal import *
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
def SieveOfEratosthenes(n): 
    prime=[]
    primes = [True for i in range(n+1)] 
    p = 2
    while (p * p <= n): 
          
        if (primes[p] == True): 
            prime.append(p)
            for i in range(p * p, n+1, p): 
                primes[i] = False
        p += 1
    return prime
#--------------------------------------------------------
s1=input()
s2=input()
if len(s1)>len(s2):
    s1,s2=s2,s1
se1=set()
se2=set()
for i in range(0,len(s1)):
    c=len(s1[:i+1])
    if len(s1)%c==0 and s1[:i+1]*(len(s1)//c)==s1:
        se1.add(s1[:i+1])
for i in range(0,len(s2)):
    c=len(s2[:i+1])
    if len(s2)%c==0 and s2[:i+1]*(len(s2)//c)==s2:
        se2.add(s2[:i+1])
se1.add(s1)
se1=se1.intersection(se2)
print(len(se1))