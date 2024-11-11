# ------------------- fast io --------------------
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
 
# ------------------- fast io --------------------
#union find
def find(node):
    comp=[]
    while group[node]!=node:
        comp.append(node)
        node=group[node]
    for i in comp:
        group[i]=node
    return group[node]
for j in range(int(input())):
    n,m,k=map(int,input().split())
    #cities, roads and speed limit
    group=[s for s in range(n)]
    info=[];nearest=10**10
    for s in range(m):
        x,y,s1=map(int,input().split())
        x-=1;y-=1
        if abs(k-s1)<abs(k-nearest):
            nearest=s1
        if s1<=k:
            info.append((x,y,0))
        else:
            info.append((x,y,s1-k))
    info.sort(key=lambda x: x[2])
    #minimum spanning tree
    ans=0
    for s in range(m):
        edge=(info[s][0],info[s][1]);cost=info[s][2]
        #check if theyre unified
        g1=find(edge[0]);g2=find(edge[1])
        if g1!=g2:
            #connect them
            group[g2]=g1
            ans+=cost
    if ans!=0:
        print(ans)
    else:
        print(abs(k-nearest))