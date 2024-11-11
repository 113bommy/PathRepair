import sys, os
from io import BytesIO, IOBase
from math import floor, gcd, fabs, factorial, fmod, sqrt, inf, log
from collections import defaultdict as dd, deque
from heapq import merge, heapify, heappop, heappush, nsmallest
from bisect import bisect_left as bl, bisect_right as br, bisect

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

stdin, stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout) 

mod = pow(10, 9) + 7
mod2 = 998244353
        
def inp(): return stdin.readline().strip()
def iinp(): return int(inp())
def out(var, end="\n"): stdout.write(str(var)+"\n")
def outa(*var, end="\n"): stdout.write(' '.join(map(str, var)) + end)
def lmp(): return list(mp())
def mp(): return map(int, inp().split())
def l1d(n, val=0): return [val for i in range(n)]
def l2d(n, m, val=0): return [l1d(m, val) for j in range(n)]
def ceil(a, b): return (a+b-1)//b
S1 = 'abcdefghijklmnopqrstuvwxyz'
S2 = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
def isprime(x):
    if x<=1: return False
    if x in (2, 3): return True
    if x%2 == 0: return False
    for i in range(3, int(sqrt(x))+1, 2):
        if x%i == 0: return False
    return True
 
n, k = mp()
a, b, ab = l2d(3, 0)
for i in range(n):
    x, y, z = mp()
    if y==z==1:
        ab.append(x)
    elif y==1:
        a.append(x)
    elif x==1:
        b.append(x)
if min(len(b), len(a))+len(ab)<k:
    print(-1)
    exit()
a.sort(reverse=True)
b.sort(reverse=True)
ab.sort(reverse=True)
ans = 0
i = 0
while i < k:
    if len(a)==0 or len(b)==0:
        ans += ab.pop()
    elif len(ab)==0:
        ans += a.pop() + b.pop()
    else:
        x, y, z = a[-1], b[-1], ab[-1]
        if x+y < z:
            ans += a.pop()+b.pop()
        else:
            ans += ab.pop()
    i+=1
print(ans)
