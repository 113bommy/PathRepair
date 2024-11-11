import math 
#------------------------------warmup----------------------------
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
 
#-------------------game starts now----------------------------------------------------
n=int(input())
d=dict()
d1=dict()
for i in range(n-2):
    a,b,c=map(int,input().split())
    if (min(a,b),max(a,b)) in d:
        d[(min(a,b),max(a,b))].append(c)
    else: 
        d.update({(min(a,b),max(a,b)):[c]})
    if (min(c,b),max(c,b)) in d:
        d[(min(c,b),max(c,b))].append(a)
    else: 
        d.update({(min(c,b),max(c,b)):[a]})
    if (min(a,c),max(a,c)) in d:
        d[(min(a,c),max(a,c))].append(b)
    else: 
        d.update({(min(a,c),max(a,c)):[b]})
    if a in d1:
        d1[a]+=1
    else:
        d1.update({a:1})
    if b in d1:
        d1[b]+=1
    else:
        d1.update({b:1})
    if c in d1:
        d1[c]+=1
    else:
        d1.update({c:1})
ans=[]
for i in range(1,n+1):
    if d1[i]==1:
        ans.append(i)
        st=i
        break
for i in range(1,n+1):
    if d1[i]==2 and (min(i,st),max(i,st)) in d:
        ans.append(i)
#print(ans)
s=set(ans)
for i in range(2,n):
    for j in d[(min(ans[i-2],ans[i-1]),max(ans[i-2],ans[i-1]))]:
        if j in s: 
            continue 
        ans.append(j)
        s.add(j)
print(*ans,sep=" ")