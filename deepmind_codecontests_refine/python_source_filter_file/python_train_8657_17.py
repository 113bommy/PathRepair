#------------------------template--------------------------#
import os
import sys
from math import *
from collections import *
# from fractions import *
# from heapq import*
from bisect import *
from io import BytesIO, IOBase
def vsInput():
    sys.stdin = open('input.txt', 'r')
    sys.stdout = open('output.txt', 'w')
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
ALPHA='abcdefghijklmnopqrstuvwxyz'
M=998244353
EPS=1e-6
def Ceil(a,b): return a//b+int(a%b>0)
def value():return tuple(map(int,input().split()))
def array():return [int(i) for i in input().split()]
def Int():return int(input())
def Str():return input()
def arrayS():return [i for i in input().split()]


#-------------------------code---------------------------#
# vsInput()


def AP(b):

    d = b[1][0] - b[0][0]
    for i in range(1,len(b)):
        if(b[i][0] - b[i-1][0] != d): return False
    return True


n = Int()
a = array()

a = [(a[i],i+1) for i in range(n)]
a.sort()

d = defaultdict(int)
for i in range(1,n):
    d[a[i][0] - a[i-1][0]] +=1



if( AP(a) ): print(1)
elif( AP(a[1:]) ): print(a[0][1])
elif( AP(a[:-1]) ): print(a[-1][1])
else:

    for i in range(1,n-1):

        d1 = a[i][0] - a[i-1][0]
        d2 = a[i+1][0] - a[i][0]

        d[d1] -= 1
        d[d2] -= 1

        if(not d[d1]): del d[d1]
        if(not d[d2]): del d[d2]

        d3 = a[i+1][0] - a[i-1][0]

        d[d3] += 1

        if(len(d) == 1):
            print(a[i][1])
            exit()

        d[d3] -= 1
        if(not d[d3]): del d[d3]

        d[d1] += 1
        d[d2] += 1

    print(-1)









    

































