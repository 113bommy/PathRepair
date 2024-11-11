#Code by Sounak, IIESTS
#------------------------------warmup----------------------------

import os
import sys
import math
from io import BytesIO, IOBase
from fractions import Fraction
import collections
from itertools import permutations
#from collections import defaultdict
from collections import deque
import threading



#sys.setrecursionlimit(300000)
#threading.stack_size(10**8)


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

#-------------------game starts now-----------------------------------------------------
class Factorial:
    def __init__(self, MOD):
        self.MOD = MOD
        self.factorials = [1, 1]
        self.invModulos = [0, 1]
        self.invFactorial_ = [1, 1]
 
    def calc(self, n):
        if n <= -1:
            print("Invalid argument to calculate n!")
            print("n must be non-negative value. But the argument was " + str(n))
            exit()
        if n < len(self.factorials):
            return self.factorials[n]
        nextArr = [0] * (n + 1 - len(self.factorials))
        initialI = len(self.factorials)
        prev = self.factorials[-1]
        m = self.MOD
        for i in range(initialI, n + 1):
            prev = nextArr[i - initialI] = prev * i % m
        self.factorials += nextArr
        return self.factorials[n]
 
    def inv(self, n):
        if n <= -1:
            print("Invalid argument to calculate n^(-1)")
            print("n must be non-negative value. But the argument was " + str(n))
            exit()
        p = self.MOD
        pi = n % p
        if pi < len(self.invModulos):
            return self.invModulos[pi]
        nextArr = [0] * (n + 1 - len(self.invModulos))
        initialI = len(self.invModulos)
        for i in range(initialI, min(p, n + 1)):
            next = -self.invModulos[p % i] * (p // i) % p
            self.invModulos.append(next)
        return self.invModulos[pi]
 
    def invFactorial(self, n):
        if n <= -1:
            print("Invalid argument to calculate (n^(-1))!")
            print("n must be non-negative value. But the argument was " + str(n))
            exit()
        if n < len(self.invFactorial_):
            return self.invFactorial_[n]
        self.inv(n)  # To make sure already calculated n^-1
        nextArr = [0] * (n + 1 - len(self.invFactorial_))
        initialI = len(self.invFactorial_)
        prev = self.invFactorial_[-1]
        p = self.MOD
        for i in range(initialI, n + 1):
            prev = nextArr[i - initialI] = (prev * self.invModulos[i % p]) % p
        self.invFactorial_ += nextArr
        return self.invFactorial_[n]
 
 
class Combination:
    def __init__(self, MOD):
        self.MOD = MOD
        self.factorial = Factorial(MOD)
 
    def ncr(self, n, k):
        if k < 0 or n < k:
            return 0
        k = min(k, n - k)
        f = self.factorial
        return f.calc(n) * f.invFactorial(max(n - k, k)) * f.invFactorial(min(k, n - k)) % self.MOD
#-------------------------------------------------------------------------
n,m=map(int,input().split())
a=list()
for i in range (n):
    b=input()
    a.append(b)
p=[['.' for i in range (m)]for j in range (n)]
r=list()
for i in range (1,n-1):
    for j in range (1,m-1):
        if a[i][j]=='*':
            mn=1000
            c=0
            for k in range (i-1,-1,-1):
                if a[k][j]=='*':
                    c+=1
                else:
                    break
            mn=min(mn,c)
            c=0
            for k in range (i+1,n):
                if a[k][j]=='*':
                    c+=1
                else:
                    break
            mn=min(mn,c)
            c=0
            for k in range (j-1,-1,-1):
                if a[i][k]=='*':
                    c+=1
                else:
                    break
            mn=min(mn,c)
            c=0
            for k in range (j+1,m):
                if a[i][k]=='*':
                    c+=1
                else:
                    break
            mn=min(mn,c)
            #print(i,j,mn)
            if mn>0:
                p[i][j]='*'
                r.append((i+1,j+1,mn))
                for k in range (i-1,i-mn-1,-1):
                    p[k][j]='*'
                for k in range (i+1,i+mn+1):
                    p[k][j]='*'
                for k in range (j-1,j-mn-1,-1):
                    p[i][k]='*'
                for k in range (j+1,j+mn+1):
                    p[i][k]='*'
ch=1
for i in range (n):
    for j in range (m):
        if a[i][j]!=p[i][j]:
            ch=0
            break
if ch:
    print(len(r))
    for i in r:
        print(*i)
else:
    print(-1)