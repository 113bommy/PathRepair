'''
Github: https://github.com/Devansh3712
'''

import os
import sys
import math
import itertools
from io import BytesIO, IOBase
import os.path

# <fast I/O>
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
# </fast I/O>

# <template>
mod = (10**9)+7
pi = 3.14159265358979323846264338327950


def i1():  # int(input())
    return int(sys.stdin.readline())


def sf():  # input()
    return sys.stdin.readline()


def mi():  # map(int(input()))
    return map(int, sys.stdin.readline().split())


def arr():  # list(map(int,input().split()))
    return list(map(int, sys.stdin.readline().split()))


def pf(ans):  # print(x)
    return sys.stdout.write(str(ans)+"\n")


def gcd(a, b):
    a=abs(a)
    b=abs(b)
    if a == 0:
        return b
    elif b == 0:
        return a
    if a > b:
        return gcd(a % b, b)
    else:
        return gcd(a, b % a)


def lcm(a, b):
    return (a*b)//gcd(a, b)


# </template>
# <testcases>
if(os.path.exists('input_file.txt')):
    sys.stdin = open("input_file.txt", "r")
    sys.stdout = open("output_file.txt", "w")
# </testcases>



def SOE(n):
    prime = [True for i in range(n + 1)] 
    p = 2
    while (p * p <= n): 
        if (prime[p] == True): 
            for i in range(p * 2, n + 1, p): 
                prime[i] = False
        p += 1
    prime[0]= False
    prime[1]= False
    return prime
def printDivisors(n,b) :
    i = 1
    l=[]
    while i*i <= (n):
        if i>=b:break
    
        if (n % i == 0) :
            if (n / i == i) :
                l.append(i)
            else :
                l.append(i)
                if n/i<b:
                    l.append(n/i)
        i = i + 1
    return l

def solve():
    deg1,deg2=map(int,input().split())
    a=list(map(int,input().split()))
    b=list(map(int,input().split()))
    if deg1>deg2:
        if a[0]>0:return 'Infinity'
        else:return '-Infinity'
    elif deg1<deg2:
        aa=b[0]
        # aa=str(a)
        return '0/'+'1'
    else:
        p=''
        if a[0]*b[0]<0:p='-'
        g=gcd(a[0],b[0])
        aa=p+str(abs(a[0])//g)+'/'+str(abs(b[0])//g)
        return aa


# <solution>
tc = 1
for t in range(tc):
    ans=solve()
    print(ans)
# <solution>


