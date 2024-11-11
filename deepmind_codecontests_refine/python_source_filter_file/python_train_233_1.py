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
 
# ------------------------------
 
def RL(): return map(int, sys.stdin.readline().rstrip().split())
def RLL(): return list(map(int, sys.stdin.readline().rstrip().split()))
def N(): return int(input())
def print_list(l):
    print(' '.join(map(str,l)))
# import heapq as hq
# import bisect as bs
# from collections import deque as dq
from collections import defaultdict as dc 
# from math import ceil,floor,sqrt
# from collections import Counter



n,k = RL()

M = 998244353

v = [1]*(n+1)
for i in range(1,n+1):
    v[i] = (v[i-1]*i)%M
v2 = [0]*(n+1)
v2[n-k] = pow(v[n-k],M-2,M)
v2[0] = 1
for i in range(n-k-1,0,-1):
    v2[i] = (v2[i+1]*(i+1))%M
# print(v)
# print(v2)
res = 0
ll = dc(set)
rr = dc(set)
for i in range(n):
    l,r = RL() 
    ll[l].add(i)
    rr[r+1].add(i)
al = sorted(list(set(list(ll.keys())+list(rr.keys()))))
# print(p,al,ll,rr)
last = al[0]
now = ll[last]
ln = len(now)
if ln>=k:
    res+=(v[ln]*v2[k]*v2[ln-k])%M
# print(res)
for time in al[1:]:
    now -= rr[time]
    ln = len(now)
    if ln>=k:
        res-=(v[ln]*v2[k]*v2[ln-k])%M
    now |= ll[time]
    ln = len(now)
    if ln>=k:
        res+=(v[ln]*v2[k]*v2[ln-k])%M
    res%=M
print(res)