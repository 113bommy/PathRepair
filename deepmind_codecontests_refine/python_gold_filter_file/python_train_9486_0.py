

# Legends Always Come Up with Solution
# Author: Manvir Singh

import os
from io import BytesIO, IOBase
import sys
from heapq import *
from collections import deque

inf=1000000000000000

def main():
    n,m,k=map(int,input().split())
    tree,b=[[] for _ in range(n+1)],{}
    for i in range(m):
        x,y,z=map(float,input().split())
        x,y=int(x),int(y)
        b[(x,y)],b[(y,x)]=i+1,i+1
        tree[x].append((y,z))
        tree[y].append((x,z))
    dis,ans,v,p=[inf]*(n+1),[],[0]*(n+1),[0]*(n+1)
    dis[1]=0
    a=[(0,1)]
    while a and len(ans)!=k:
        d,node=heappop(a)
        if v[node]:
            continue
        v[node]=1
        if p[node]:
            ans.append((p[node],node))
        if dis[node]<d:
            continue
        for x,y in tree[node]:
            if dis[x]>d+y:
                dis[x]=d+y
                heappush(a,(d+y,x))
                p[x]=node
    print(len(ans))
    for i in ans:
        print(b[i],end=" ")

# FAST INPUT OUTPUT REGION

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