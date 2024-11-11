import os
import sys
from io import BytesIO, IOBase
# region fastio
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
input = lambda: sys.stdin.readline()
 
# ------------------------------


def RL(): return map(int, sys.stdin.readline().split())
def RLL(): return list(map(int, sys.stdin.readline().split()))
def N(): return int(input())
def print_list(l):
    print(' '.join(map(str,l)))
# sys.setrecursionlimit(300000)
# from heapq import *
# from collections import deque as dq
from math import ceil,floor,sqrt,pow
# import bisect as bs
# from collections import Counter
# from collections import defaultdict as dc 

for i in range(N()):
    n = N()
    nn,k = n,2
    p,d = [],[i for i in range(2,int(sqrt(n))+1) if n%i==0]
    d+=[n//i for i in d]
    d = set(d)
    d.add(n)
    # print(d)
    for i in d:
        if nn%i==0:
            p.append(i)
            while nn%i==0:
                nn//=i
    # print(d)
    # print(p)
    if len(p)==1:
        print_list(d)
        print(0)
    elif len(p)==2:
        if len(d)==3:
            print_list(d)
            print(1)
        else:
            a,b = p[0],p[1]
            res = [a*b,a]
            d-={a*b,a,n}
            for i in d:
                if i%a==0:
                    res.append(i)
            res.append(n)
            for i in d:
                if i%a>0:
                    res.append(i)
            print_list(res)
            print(0)
    else:
        res = []
        s = 1
        pp = [p[i]*p[i-1] for i in range(1,len(p))]+[p[0]*p[-1]]
        d-=set(pp)
        d-=set(p)
        for i in range(len(p)):
            k = p[i]
            for t in d:
                if t%k==0:
                    res.append(t)
            d-=set(res[s:])
            s = len(res)
            res.append(p[i])
            res.append(pp[i])
        print_list(res)
        print(0)





            
