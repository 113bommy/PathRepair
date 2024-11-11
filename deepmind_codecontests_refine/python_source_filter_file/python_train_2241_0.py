#------------------------template--------------------------#
import os
import sys
from math import *
from collections import *
from fractions import *
from bisect import *
from heapq import*
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
M=1000000007
EPS=1e-6
def value():return tuple(map(int,input().split()))
def array():return [int(i) for i in input().split()]
def Int():return int(input())
def Str():return input()
def arrayS():return [i for i in input().split()]


#-------------------------code---------------------------#
# vsInput()
    

a,b,c,d,n=value()
area=array()


ans=[['.' for i in range(a+c)] for j in range(max(b,d))]

rev=False
if(d<b):
    a,c=c,a
    b,d=d,b
    rev=True

# print(a,b)

ind=0
for j in range(a):
    for i in range(b):
        if(area[ind]==0):
            ind+=1

        if(c%2==0):
            if(j%2==0): ans[i][j]=ALPHA[ind]
            else: ans[b-i-1][j]=ALPHA[ind]
        else:
            if(j%2): ans[i][j]=ALPHA[ind]
            else: ans[b-i-1][j]=ALPHA[ind]
        area[ind]-=1


_j=-1
for j in range(a,a+c):
    _j+=1
    for i in range(d):
        if(area[ind]==0):
            ind+=1

        if(_j%2==0): ans[i][j]=ALPHA[ind]
        else: ans[d-i-1][j]=ALPHA[ind]
        area[ind]-=1

print("YES")
for i in ans:
    if(rev):
        print(*i[::-1],sep="")
    else:
        print(*i,sep="")























    