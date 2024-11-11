# Legends Always Come Up with Solution
# Author: Manvir Singh

import os
import sys
from io import BytesIO, IOBase
from collections import Counter

mod=998244353

def solve(arr,n,f):
    a=sorted(range(n),key=lambda x:arr[x])
    i,ans=0,1
    while i<n:
        j=i+1
        while j<n and arr[a[i]]==arr[a[j]]:
            j+=1
        ans=(ans*f[j-i])%mod
        i=j
    return ans

def issorted(a):
    for i in range(len(a)-1):
        if a[i+1]<a[i]:
            return 0
    return 1

def main():
    n=int(input())
    a,b=[],[]
    for i in range(n):
        x,y=map(int,input().split())
        a.append(x)
        b.append(y)
    f= [1]
    for i in range(1, n + 1):
        f.append((f[-1] * i) % mod)
    ans1,ans2,ans3=solve(a,n,f),solve(b,n,f),1
    ans=(f[n]-ans1-ans2)%mod
    c=sorted(range(n),key=lambda x:a[x])
    i,d= 0,[]
    while i < n:
        j = i + 1
        while j < n and a[c[i]] == a[c[j]]:
            j += 1
        e=[]
        for k in range(i,j):
            e.append(b[c[k]])
        e.sort()
        d.extend(e)
        g=Counter(e)
        for k in g:
            ans3=(ans3*g[k])%mod
        i=j
    print((ans+issorted(d)*ans3)%mod)

# FASTIO REGION

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

if __name__ == "__main__":
    main()