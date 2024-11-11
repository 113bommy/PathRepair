import os
import heapq
import sys
import math
import bisect
import operator
from collections import defaultdict
from io import BytesIO, IOBase


def prime_factors(n):  #to calculate set of prime factors
    i = 2
    factors = set()
    while i * i <= n:
        if n % i:
            i += 1
        else:
            factors.add(n // i)
            n = n // i
            factors.add(i)

    if n > 1:
        factors.add(n)
    return factors


def isPrime(n):  # <-----------check whether a no. is prime or not
    if n == 2 or n == 3: return True
    if n % 2 == 0 or n < 2: return False
    for i in range(3, int(n ** 0.5) + 1, 2):  # only odd numbers
        if n % i == 0:
            return False

    return True
# def gcd(a,b):
#     if b==0:

#         return a
#     else:
#         return gcd(b,a%b)Aa
def inar():
    return [int(k) for k in input().split()]
def gcd(a,b):
    if b==0:
        return a
    return gcd(b,a%b)
def lcmm(a,b):
    return (a*b)//gcd(a,b)
def main():
    # mod=10**9+7
    #for _ in range(int(input())):
    n=int(input())
    arr=inar()
    if n==1:
        print(arr[0])
    else:
        prefix=[arr[0],arr[1]]
        for i in range(2,n):
            prefix.append(prefix[i-2]+arr[i])
        suffix=[0]*n
        for i in range(n-1,-1,-1):
            if (i+2)>n-1:
                suffix[i]=arr[i]
            else:
                suffix[i]=arr[i]+suffix[i+2]
        ans=0
        # print(prefix)
        # print(suffix)
        #print(arr)
        for i in range(n):
            if (i-1)==-1:
                ans=max(ans,suffix[i]+0)
            else:
                ans = max(ans, suffix[i] + prefix[i - 1])
        print(ans)


















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

if __name__ == "__main__":
    main()