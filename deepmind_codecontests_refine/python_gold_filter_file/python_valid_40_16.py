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
from collections import defaultdict
from math import ceil,floor,sqrt,log2,gcd,pi
from heapq import heappush,heappop
from fractions import Fraction
from bisect import bisect_left,bisect
import sys
abc='abcdefghijklmnopqrstuvwxyz'
ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ"

for i in range(int(input())):
    n=int(input())
    r1=list(map(int,input().split()))
    r2=list(map(int,input().split()))
    for i in range(n-2,0,-1):
        r1[i]+=r1[i+1]
    r1[0]=0
    # print(r1)
    r2[-1]=0
    for i in range(1,n-1):
        r2[i]+=r2[i-1]
    # print(r2)
    if n==1:
        print(0)
    elif n==2:
        print(min(r1[-1],r2[0]))
    else:
        arr=[]
        for i in range(n):
            # print(arr)
            if i==0:
                arr.append(r1[1])
            elif i==n-1:
                arr.append(r2[-2])
            else:
                arr.append(max(r1[i+1],r2[i-1]))
        arr.sort()
        print(min(arr))
            
    # pre=[0]*n
    # pre[0]=r1[0]
    # for i in range(1,n):
    #     pre[i]+=r1[i]+pre[i-1]
    # post=[0]*n
    # post[-1]=r2[-1]
    # for i in range(n-2,-1,-1):
    #     post[i]+=r2[i]+post[i+1]
    # print(pre,post)
    # pos=0
    # maxi=pre[0]+post[0]
    # for i in range(n):
    #     val=pre[i]+post[i]
    #     if val<maxi:
    #         maxi=val
    #         pos=i
    # print(maxi,pos)