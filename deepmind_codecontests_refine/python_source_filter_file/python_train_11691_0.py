#!/usr/bin/env python
import os
import sys,math
from io import BytesIO, IOBase
# from itertools import permutations, combinations
# from collections import defaultdict,deque,OrderedDict
# from os import path
# import random
# import bisect as bi
def yes():print('YES')
def no():print('NO')
def I():return (int(input()))
def In():return(map(int,input().split()))

#complete the main function with number of test cases to complete
class Segmenttreemx():
    st,n=[],0
    def __init__(self,n,l):
        self.st=[-P]*(4*n)
        self.n=n
        for i in range(n):
            self.st[i+n]=l[i]
        for i in range(n-1,0,-1):
            self.st[i]=max(self.st[i<<1],self.st[i<<1 | 1])

    def update(self,p,val):
        self.st[p+self.n]=val
        p+=self.n
        while p>1:
            self.st[p>>1]=max( self.st[p],self.st[p^1])
            p>>=1
            
    def query(self,l,r):
        l,r=l+self.n,r+self.n
        res=-P
        while l<r:
            if l&1:
                res=max(res,self.st[l])
                l+=1
            if r&1:
                r-=1
                res=max(res,self.st[r])
            l>>=1
            r>>=1
        return res

class Segmenttreemn():
    st,n=[],0
    def __init__(self,n,l):
        self.st=[P]*(4*n)
        self.n=n
        for i in range(n):
            self.st[i+n]=l[i]
        for i in range(n-1,0,-1):
            self.st[i]=min(self.st[i<<1],self.st[i<<1 | 1])

    def update(self,p,val):
        self.st[p+self.n]=val
        p+=self.n
        while p>1:
            self.st[p>>1]=min( self.st[p],self.st[p^1])
            p>>=1
            
    def query(self,l,r):
        l,r=l+self.n,r+self.n
        res=P
        while l<r:
            if l&1:
                res=min(res,self.st[l])
                l+=1
            if r&1:
                r-=1
                res=min(res,self.st[r])
            l>>=1
            r>>=1
        return res

def main():
    try:
        n,nQ=In()
        s=Sn()
        cnt=0
        L=[0]
        for x in s:
            if x=='+':
                cnt+=1
            else:
                cnt-=1
            L.append(cnt)
        # L1=L[1:].copy()
        Sgmn=Segmenttreemn(n,L[1:])
        Sgmx=Segmenttreemx(n,L[1:])
        # print(Sgmx.st)
        # print(Sgmx.query(1,n))

        for x in range(nQ):
            l,r=In()
            mx1,mx2,mn2,mn1=0,0,0,0
            if l-1>=0:
                mx1=max(0,Sgmx.query(0,l-1))
                mn1=min(0,Sgmn.query(0,l-1))
            if r<n:
                temp=L[r]-L[l-1]
                mx2=(-temp+Sgmx.query(r,n))
                mn2=(-temp+Sgmn.query(r,n))
            mn2=min(mn2,mn1)
            mx2=max(mx2,mx1)
            print(mx2-mn2+1)
    except:
        pass

M = 998244353
P = 1000000007
 

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

if __name__ == '__main__':
    for _ in range(I()):main()
    # for _ in range(1):main()
