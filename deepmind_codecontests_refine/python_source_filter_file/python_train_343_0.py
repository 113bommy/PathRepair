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
##########################################################
#print('%d %d' %ans)
from collections import Counter
import math

#for _ in range(int(input())):
#n=int(input())
n,k= map(int, input().split())
s=[]
p=[]
ex=1e9
for i in range(n):
    c,t = map(int, input().split())
    ex = min(ex, c)
    if t==1:
        s.append((c,i))
    else:
        p.append((c,i))
s.sort(reverse=True)
var=0
cost=0

ans=[[] for i in range(k)]
for i,j in s:
    ans[var].append((j+1))
    if var<k-1:
        cost+=i
        var+=1
    else:
        cost+=2*i
for i,j in p:
    ans[var].append((j+1))
    if var<k-1:var+=1
    cost+=2*i
#print("%.1f"%cost/2)
if len(s)==k:
    cost-=ex
cost=cost/2
print("%.1f"%cost)

for i in ans:
    print(len(i), *i)



