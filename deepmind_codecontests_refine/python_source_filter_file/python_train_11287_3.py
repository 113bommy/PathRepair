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

n=int(input())
arr=list(map(int,input().split()))
arr.sort()
d=defaultdict(int)
for i in range(1,n):
    d[arr[i]-arr[i-1]]+=1
if len(arr)==1:
    print(-1)
elif len(arr)==2:
    diff=arr[-1]-arr[0]
    if diff>=2 and diff%2==0:        
        print(3)
        print(arr[0]-arr[-1]+arr[0],(arr[0]+arr[-1])//2,arr[-1]+arr[-1]-arr[0])
    elif diff!=0:
        print(2)
        print(arr[0]-arr[-1]+arr[0],arr[-1]+arr[-1]-arr[0])
    else:
        print(1)
        print(arr[0])
else:
    if len(d)>2:
        print(-1)
    elif len(d)==1:
        if min(arr)!=max(arr):        
            print(2)
            print(arr[0]-arr[1]+arr[0],arr[-1]+arr[-1]-arr[-2])
        else:
            print(1)
            print(max(arr))
    elif len(d)==2:
        a=list(d.keys())
        a.sort()
        if a[-1]==2*a[0] and d[a[1]]==1:
            print(1)
            for i in range(1,n):
                if arr[i]-arr[i-1]!=a[0]:
                    print(arr[i-1]+a[0])
                    break
            
        else:
            print(0)
        
    