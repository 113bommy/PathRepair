#!/usr/bin/env python
import os
import sys
from io import BytesIO, IOBase
import threading 
from bisect import bisect_right
from math import gcd,log
from collections import Counter
from pprint import pprint
from itertools import permutations 
from bisect import bisect_right



def main():
    n,p=map(int,input().split())
    arr=list(map(int,input().split()))
    brr=[]
    for i in range(n):

        brr.append((arr[i],i))

    brr.sort()
    brr.reverse()
    connected=[0]*n
    ans=0
    for i in range(n):
        val,idx=brr.pop()
        if val>p:
            break
        if connected[idx]:
            continue
        for i in range(idx-1,-1,-1):
            if connected[i]==0 and arr[i]%val==0:
                # print(i,idx)
                ans+=val
                connected[i]=1
            else:
                break

        for i in range(idx+1,n-1,+1):
            if connected[i]==0 and arr[i]%val==0:
                # print(i,idx)
                ans+=val
                connected[i]=1
            else:
                break

    sm=sum(connected)
    print(ans+p*(n-1-sm))


 
    








        
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



