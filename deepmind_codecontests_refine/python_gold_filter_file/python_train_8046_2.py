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
input = lambda: sys.stdin.readline().rstrip("\r\n")
#https://github.com/cheran-senthil/PyRival/blob/master/templates/template_py3.py


from collections import defaultdict

def toposort(graph):
    res = []
    found = [0] * len(graph)
    stack = list(range(len(graph)))
    while stack:
        node = stack.pop()
        if node < 0:
            res.append(1+(~node))
        elif not found[node]:
            found[node] = 1
            stack.append(~node)
            stack.extend(graph[node])
 
    # cycle check
    for node in res:
        node-=1
        if any(found[nei] for nei in graph[node]):
            print("NO")
            return
        found[node] = 0
 
    print("YES")
    print(*res[::-1])
    
#https://github.com/cheran-senthil/PyRival/blob/master/pyrival/graphs/toposort.py

n,m,k=map(int,input().split())
patterns=set()
pos=dict()

for i in range(n):
    p=input().rstrip()
    patterns.add(p)
    pos[p]=i
    
matches=[[] for _ in range(n)]

chk=True
for i in range(m):
    s,mt=input().rstrip().split()
    mt=int(mt)-1
    if(chk):
        chk=False
        for i in range(1<<k):
            tmp=[]
            for j in range(k):
                if(i&(1<<j)):
                    tmp.append('_')
                else:
                    tmp.append(s[j])
            tmp=''.join(tmp)
            if(tmp in patterns):
                if(mt==pos[tmp]):
                    chk=True
                else:
                    matches[mt].append(pos[tmp])
                    
if(not chk):
    print("NO")
else:
    toposort(matches)
    
        
            
            
            
        