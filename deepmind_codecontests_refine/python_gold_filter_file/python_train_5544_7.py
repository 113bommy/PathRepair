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
input = lambda: sys.stdin.readline()
 
# ------------------------------
 
def RL(): return map(int, sys.stdin.readline().split())
def RLL(): return list(map(int, sys.stdin.readline().split()))
def N(): return int(input())
def print_list(l):
    print(' '.join(map(str,l)))
# import heapq as hq
# import bisect as bs
# from collections import deque as dq
# from collections import defaultdict as dc 
# from math import ceil,floor,sqrt
# from collections import Counter

data = [map(int, line.split()) for line in sys.stdin.readlines()]
# data = [RLL()]

# for _ in range(data[0][1]):
#     data.append(RL())
n,m,k = data[0]
dic = [[] for _ in range(n+1)]
for i in range(1,m+1):
    u,v = data[i]
    dic[u].append(v)
    dic[v].append(u)
now = [1]
father = [-1]*(n+1)
p = [0]*(n+1)
iscycle = False
while now:
    node = now.pop()
    for child in dic[node]:
        if child!=father[node]:
            # print(child,'*')
            if father[child]!=-1:
                iscycle = True
                odd = [child,node]
                break
            father[child] = node 
            p[child] = p[node]+1
            now.append(child)
    if iscycle:
        break
# print(iscycle)
# print(p)
# print(father)
if iscycle:
    a,b = odd[0],odd[1]
    x,y = [],[]
    node = a 
    while node>1:
        x.append(node)
        node = father[node]
    x.append(1)
    u = set(x)
    node = b
    while node>1:
        y.append(node)
        node = father[node] 
        if node in u:
            t = p[a]-p[node]+1
            x = x[:t]
            break
    # print(a,b,x,y) 
    x+=y[::-1]
    if len(x)<=k:
        print(2)
        print(len(x))
        print_list(x)
    else:
        print(1)
        print_list(x[:k:2])
else:
    print(1)
    s0 = [i for i in range(1,n+1) if p[i]&1==0]
    s1 = [i for i in range(1,n+1) if p[i]&1==1]
    if len(s0)>len(s1):
        print_list(s0[:(k+1)>>1])
    else:
        print_list(s1[:(k+1)>>1])

