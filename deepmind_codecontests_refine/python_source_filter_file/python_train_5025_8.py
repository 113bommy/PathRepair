import os
import heapq
import sys,threading
import math
import operator
from collections import defaultdict,deque
from io import BytesIO, IOBase

sys.setrecursionlimit(10 ** 5)
#threading.stack_size(2**27)


def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)


"""def pw(a,b):
    result=1
    while(b>0):
        if(b%2==1): result*=a
        a*=a
        b//=2
    return result"""


def inpt():
    return [int(k) for k in input().split()]

def bfs1(d,node,n):
    visited = [False] * (n + 1)
    q = deque()
    q.append(node)
    visited[node] = True
    dist = [10000000000] * (n + 1)
    dist[node] = 0
    global mx
    while(q):
        x=q.popleft()
        for i in d[x]:
            dist[i] = min(dist[i], dist[x] + 1)
            if (dist[i] > mx):
                mx = dist[i]
            if (not visited[i]):
                visited[i] = True
                q.append(i)

def bfs(d,s,n,b):
    visited=[False]*(n+1)
    q=deque()
    q.append(s)
    visited[s]=True
    dist=[10000000000]*(n+1)
    dist[s]=0
    global mx,node
    while(q):
        x=q.popleft()
        for i in d[x]:
            dist[i]=min(dist[i],dist[x]+1)
            if(dist[i]>mx):
                mx=dist[i]
                node=i

            if(not visited[i]):
                visited[i]=True
                q.append(i)

    return dist[b]

def main():
    for _ in range(int(input())):
        n,a,b,da,db=inpt()
        d=defaultdict(list)

        for _ in range(n-1):
            u,v=inpt()
            d[u].append(v)
            d[v].append(u)

        global mx,node
        mx=0

        dist=bfs(d,a,n,b)
        mx=0
        if(dist<=da):
            print('Alice')
            continue
        bfs1(d,node,n)
        if(mx<=da):
            print('Alice')
            continue
        if(2*da<db):
            print('Bob')
            continue
        else:
            print('Alice')



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
    #threading.Thread(target=main).start()
