#!/usr/bin/env python
import os
import sys
from io import BytesIO, IOBase
import threading 
from bisect import bisect_right
from math import gcd,log
from collections import Counter 



def main():
    n,m=map(int,input().split())
    a=[0]*m
    l=[]
    b=[]
    for i in range(m):
        a[i]=tuple(map(int,input().split()))
        l.append(a[i][0])
        b.append(a[i][1])

    if (n==1):
        print(max(l))
        return
    
    pref=[0]*(m+1)

    l.sort(reverse=True)
    for i in range(m):
        pref[i+1]=pref[i]+l[i]
    l.reverse()
    print(l)
    ans=0
    if n<=m:
        ans=pref[n]
    for i in range(m):
        el,mx=a[i]
        ind=bisect_right(l,mx)
        gtr=m-ind
        # ind2=bisect_right(l,el)
        # print(el,mx,gtr,pref[gtr])
        
        if gtr<=n and el>mx:
            ans=max(ans,pref[gtr]+mx*(n-gtr))
        elif gtr+1<=n and el<=mx:
            print('yeppp')
            ans=max(ans,pref[gtr]+el+mx*(n-1-gtr))

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

# endregion

if __name__ == "__main__":
    for _ in range(int(input())):
        main()
        input()



