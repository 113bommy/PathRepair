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
#######################################
import sys,threading
sys.setrecursionlimit(4000)
threading.stack_size(10**6)
def dfs(x):
    global a,b,v,adj,l1,l2,w,l3
    v[x]=1
    a+=l1[x-1]
    b+=l2[x-1]
    if l1[x-1]<=w:
        l3.append([l1[x-1],l2[x-1]])
    for i in adj[x]:
        if not v[i]:
            dfs(i)
def main():
    global a,b,v,adj,l1,l2,w,l3
    n,m,w=map(int,input().split())
    l1=list(map(int,input().split()))
    l2=list(map(int,input().split()))
    v=[0]*(n+1)
    adj=[[] for i in range(n+1)]
    for i in range(m):
        x,y=map(int,input().split())
        adj[x].append(y)
        adj[y].append(x)
    l=[]
    dp=[0]*1001
    for i in range(1,n+1):
        if not v[i]:
            a=0
            b=0
            l3=[]
            dfs(i)
            if a<=w:
                l3.append([a,b])
            l.append(l3)
    for i in l:
        dp1=dp.copy()
        for j in i:
            dp[j[0]]=max(dp1[j[0]],j[1])
        for  j in i:
            for k in range(j[0]+1,w+1):
                if dp1[k-j[0]]:
                    dp[k]=max(dp[k],dp1[k],dp1[k-j[0]]+j[1])
    print(max(dp))
t=threading.Thread(target=main)
t.start()
t.join()
    
    
