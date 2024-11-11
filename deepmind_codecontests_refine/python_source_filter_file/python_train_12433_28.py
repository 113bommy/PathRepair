import os
import sys
from io import BytesIO, IOBase
import math
import itertools
import bisect
import heapq
def main():
    pass
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


def binary(n):
    return (bin(n).replace("0b", ""))


def decimal(s):
    return (int(s, 2))


def pow2(n):
    p = 0
    while (n > 1):
        n //= 2
        p += 1
    return (p)


def primeFactors(n):
    l = []
    while n % 2 == 0:
        l.append(2)
        n = n / 2
    for i in range(3, int(math.sqrt(n)) + 1, 2):
        while n % i == 0:
            l.append(i)
            n = n / i
    if n > 2:
        l.append(int(n))
    return (l)


def isPrime(n):
    if (n == 1):
        return (False)
    else:
        root = int(n ** 0.5)
        root += 1
        for i in range(2, root):
            if (n % i == 0):
                return (False)
        return (True)
def maxPrimeFactors(n):
    maxPrime = -1
    while n % 2 == 0:
        maxPrime = 2
        n >>= 1
    for i in range(3, int(math.sqrt(n)) + 1, 2):
        while n % i == 0:
            maxPrime = i
            n = n / i
    if n > 2:
        maxPrime = n
    return int(maxPrime)


def countcon(s, i):
    c = 0
    ch = s[i]
    for i in range(i, len(s)):
        if (s[i] == ch):
            c += 1
        else:
            break
    return (c)


def lis(arr):
    n = len(arr)
    lis = [1] * n
    for i in range(1, n):
        for j in range(0, i):
            if arr[i] > arr[j] and lis[i] < lis[j] + 1:
                lis[i] = lis[j] + 1
    maximum = 0
    for i in range(n):
        maximum = max(maximum, lis[i])
    return maximum
def isSubSequence(str1, str2):
    m = len(str1)
    n = len(str2)
    j = 0
    i = 0
    while j < m and i < n:
        if str1[j] == str2[i]:
            j = j + 1
        i = i + 1
    return j == m
def maxfac(n):
    root = int(n ** 0.5)
    for i in range(2, root + 1):
        if (n % i == 0):
            return (n // i)
    return (n)
def p2(n):
    c=0
    while(n%2==0):
        n//=2
        c+=1
    return c
def seive(n):
    primes=[True]*(n+1)
    primes[1]=primes[0]=False
    for i in range(2,n+1):
        if(primes[i]):
            for j in range(i+i,n+1,i):
                primes[j]=False
    p=[]
    for i in range(0,n+1):
        if(primes[i]):
            p.append(i)
    return(p)
def ncr(n, r, p):
    num = den = 1
    for i in range(r):
        num = (num * (n - i)) % p
        den = (den * (i + 1)) % p
    return (num * pow(den,
            p - 2, p)) % p
def denofactinverse(n,m):
    fac=1
    for i in range(1,n+1):
        fac=(fac*i)%m
    return (pow(fac,m-2,m))
def numofact(n,m):
    fac = 1
    for i in range(1, n + 1):
        fac = (fac * i) % m
    return(fac)
def chkvercro():
    if(s1.count("X")==3 or s2.count("X")==3 or s3.count("X")==3 or s1[0]==s2[0]==s3[0]=="X" or s1[1]==s2[1]==s3[1]=="X" or s1[2]==s2[2]==s3[2]=="X"or s1[0]==s2[1]==s3[2]=="X" or s1[2]==s2[1]==s3[0]=="X"):
        return True
    else:
        return False
def chkvercir():
    if (s1.count("0")==3 or s2.count("0")==3 or s3.count("0")==3 or s1[0]==s2[0]==s3[0]=="0" or s1[1]==s2[1]==s3[1]=="0" or s1[2]==s2[2]==s3[2]=="0" or s1[0]==s2[1]==s3[2]=="0" or s1[2]==s2[1]==s3[0]=="0"):
        return True
    else:
        return False
s1=input()
s2=input()
s3=input()
cro=s1.count("X")+s2.count("X")+s3.count("X")
cir=s1.count("0")+s2.count("0")+s3.count("0")
if(((cro-cir)!=0 and (cro-cir)!=1)or (chkvercro() and chkvercir())):
    print("illegal")
else:
    if chkvercir():
        if(cir==cro):
            print("the second player won")
        else:
            print("illegal")
    elif chkvercro():
        if (cro == cir):
            print("the first player won")
        else:
            print("illegal")
    else:
        if(cro+cir==9):
            print("draw")
        else:
            if(cro==cir+1):
                print("second")
            else:
                print("first")