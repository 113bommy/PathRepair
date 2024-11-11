import os,sys
from io import BytesIO, IOBase

from collections import deque, Counter,defaultdict as dft
from heapq import heappop ,heappush
from math import log,sqrt,factorial,cos,tan,sin,radians,log2,ceil,floor
from bisect import bisect,bisect_left,bisect_right
from decimal import *
import sys,threading
from itertools import permutations, combinations
from copy import deepcopy
input = sys.stdin.readline


ii = lambda: int(input())
si = lambda: input().rstrip()
mp = lambda: map(int, input().split())
ms=  lambda: map(str,input().strip().split(" "))
ml = lambda: list(mp())
mf = lambda: map(float, input().split())


alphs = "abcdefghijklmnopqrstuvwxyz"


# stuff you should look for
	#  int overflow, array bounds
	#  special cases (n=1?)
	#  do smth instead of nothing and stay organized
	#  WRITE STUFF DOWN
	#  DON'T GET STUCK ON ONE APPROACH

#

def solve():
    n,m=mp()
    arr=ml()
    dir=list(ms())
    si=[i for i in range(n)]
    si=sorted(si,key = lambda x:arr[x])
    
    sdir=[dir[idx] for idx in si]
    dir = sdir
    arr.sort() 
   
    
    ro=deque([])
    re=deque([])
    rem_lo=deque([])
    rem_le=deque([])
    res=[-1]*n
    for i in range(n):
        if dir[i]=="L":
            if arr[i]%2:
                if ro:
                    idx=ro.pop()
                    t = abs(arr[i]-arr[idx])//2
                    res[idx]=t
                    res[i]=t
                elif rem_lo:
                    idx = rem_lo.pop()
                    t = abs(arr[i]-arr[idx])//2 + arr[idx]
                    res[idx]=t
                    res[i]=t
                else:
                    rem_lo.append(i)
            else:
                if re:
                    idx=re.pop()
                    t = abs(arr[i]-arr[idx])//2
                    res[idx]=t
                    res[i]=t
                elif rem_le:
                    idx = rem_le.pop()
                    t = abs(arr[i]-arr[idx])//2 + arr[idx]
                    res[idx]=t
                    res[i]=t
                else:
                    rem_le.append(i)
        else:
            if arr[i]%2:
                ro.append(i)
            else:
                re.append(i)
    
    while(len(ro)>1):
        i=ro.pop()
        idx = ro.pop()
        t = abs(arr[i]-arr[idx])//2 + m-arr[i]
        res[idx]=t
        res[i]=t
    
    while(len(re)>1):
        i=re.pop()
        idx = re.pop()
        t = abs(arr[i]-arr[idx])//2 + m-arr[i]
        res[idx]=t
        res[i]=t
    
    if rem_lo and ro:
        i=rem_lo.pop()
        idx = ro.pop()
        x1=arr[i]
        x2=arr[idx]
        
        if x1+x2<m:
       
                t = (m-x1-x2)//2 +(m-x2) 
                res[idx]=t
                res[i]=t
        else:
            
                t = (2*m-(x1+x2) )//2 +x1
                res[idx]=t
                res[i]=t
        
    if rem_le and re:
        i=rem_le.pop()
        idx = re.pop()
        x1=arr[i]
        x2=arr[idx]
        
        if x1+x2<m:
            
                t = (m-x1-x2)//2 +(m-x2) 
                res[idx]=t
                res[i]=t
        else:
                t = (2*m-(x1+x2) )//2 +x1
                res[idx]=t
                res[i]=t
    
    
    sres=[-1]*n
    for i in range(n):
        sres[si[i]]=res[i]
    print(*sres)
                    
                    
            
    

 
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
 
 
def print(*args, **kwargs):
    """Prints the values to a stream, or to sys.stdout by default."""
    sep, file = kwargs.pop("sep", " "), kwargs.pop("file", sys.stdout)
    at_start = True
    for x in args:
        if not at_start:
            file.write(sep)
        file.write(str(x))
        at_start = False
    file.write(kwargs.pop("end", "\n"))
    if kwargs.pop("flush", False):
        file.flush()

if sys.version_info[0] < 3:
    sys.stdin, sys.stdout = FastIO(sys.stdin), FastIO(sys.stdout)
else:
    sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
 
input = lambda: sys.stdin.readline().rstrip("\r\n")
 
# endregion
 
 
if __name__ == "__main__":
    tc=1
    tc = ii()
    for i in range(tc):
    	solve()