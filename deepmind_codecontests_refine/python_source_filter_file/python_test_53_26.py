##import os
##import sys
##from io import BytesIO, IOBase
### region fastio
##BUFSIZE = 8192
## 
##class FastIO(IOBase):
##    newlines = 0
## 
##    def __init__(self, file):
##        self._fd = file.fileno()
##        self.buffer = BytesIO()
##        self.writable = "x" in file.mode or "r" not in file.mode
##        self.write = self.buffer.write if self.writable else None
## 
##    def read(self):
##        while True:
##            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
##            if not b:
##                break
##            ptr = self.buffer.tell()
##            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
##        self.newlines = 0
##        return self.buffer.read()
## 
##    def readline(self):
##        while self.newlines == 0:
##            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
##            self.newlines = b.count(b"\n") + (not b)
##            ptr = self.buffer.tell()
##            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
##        self.newlines -= 1
##        return self.buffer.readline()
## 
##    def flush(self):
##        if self.writable:
##            os.write(self._fd, self.buffer.getvalue())
##            self.buffer.truncate(0), self.buffer.seek(0)
## 
## 
##class IOWrapper(IOBase):
##    def __init__(self, file):
##        self.buffer = FastIO(file)
##        self.flush = self.buffer.flush
##        self.writable = self.buffer.writable
##        self.write = lambda s: self.buffer.write(s.encode("ascii"))
##        self.read = lambda: self.buffer.read().decode("ascii")
##        self.readline = lambda: self.buffer.readline().decode("ascii")
##
##
##
##def print(*args, **kwargs):
##    """Prints the values to a stream, or to sys.stdout by default."""
##    sep, file = kwargs.pop("sep", " "), kwargs.pop("file", sys.stdout)
##    at_start = True
##    for x in args:
##        if not at_start:
##            file.write(sep)
##        file.write(str(x))
##        at_start = False
##    file.write(kwargs.pop("end", "\n"))
##    if kwargs.pop("flush", False):
##        file.flush()
##        
##if sys.version_info[0] < 3:
##    sys.stdin, sys.stdout = FastIO(sys.stdin), FastIO(sys.stdout)
##else:
##    sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
##    
##input = lambda: sys.stdin.readline().rstrip("\r\n")
from collections import defaultdict as df
from collections import deque as dq
from heapq import heappush, heappop

def prime_sieve(n):
    """returns a sieve of primes >= 5 and < n"""
    flag = n % 6 == 2
    sieve = bytearray((n // 3 + flag >> 3) + 1)
    for i in range(1, int(n**0.5) // 3 + 1):
        if not (sieve[i >> 3] >> (i & 7)) & 1:
            k = (3 * i + 1) | 1
            for j in range(k * k // 3, n // 3 + flag, 2 * k):
                sieve[j >> 3] |= 1 << (j & 7)
            for j in range(k * (k - 2 * (i & 1) + 4) // 3, n // 3 + flag, 2 * k):
                sieve[j >> 3] |= 1 << (j & 7)
    return sieve


def prime_list(n):
    """returns a list of primes <= n"""
    res = []
    if n > 1:
        res.append(2)
    if n > 2:
        res.append(3)
    if n > 4:
        sieve = prime_sieve(n + 1)
        res.extend(3 * i + 1 | 1 for i in range(1, (n + 1) // 3 + (n % 6 == 1)) if not (sieve[i >> 3] >> (i & 7)) & 1)
    return res

from math import ceil
t = int(input())
prime_set = prime_list(300001)
for _ in range(t):
    #n = int(input())
    n,a = input().split()
    n = int(n)
    s = input()
    pos = []
    for i in range(n):
        if s[i] != a:
            pos.append(i + 1)
        
    if len(pos) == 0:
        print(0)
    
    else:
        for i in range(n - 1, -1, -1):
            if s[i] == a:
                if n % 2:
                    if i >= n//2:
                        print(1)
                        print(i + 1)
                    else:
                        print(2)
                        print(n - 1, n)
                else:
                    if i > n//2:
                        print(1)
                        print(i + 1)
                    else:
                        print(2)
                       
                        print(n - 1, n)
                break
        else:
            print(2)
            print(n - 1,n)
        
    #n,k = map(int, input().split())
##    nums = list(map(int, input().split()))
    
    
   
        
