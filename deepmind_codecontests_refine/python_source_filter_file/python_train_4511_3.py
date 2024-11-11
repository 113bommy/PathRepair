
#####################################   
import atexit, io, sys, collections, math, heapq, fractions,copy, os
from io import BytesIO, IOBase
 
#####################################  python 3 START
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
#####################################  python 3 END
'''
p = [1,2,3,4,5]
r= []
def dfs(i):
    if i == len(p):
        d = 0
        for i,e in enumerate(p):
            print(i,e)
            d += abs(e-1 -i)
            if abs(e-1 - i) == 0:
                d += +float('inf')
        r.append((d,p[::]))
        return 

    for j in range(i,len(p)):
        p[i],p[j] = p[j],p[i]
        dfs(i+1)
        p[i],p[j] = p[j],p[i]
dfs(0)    
r.sort()
for e in r:
    print (e)
print ('a')
'''
def f(n):
    if n % 2 == 1:
        return f(n-3) + [n, n-2, n-1]
    if n == 0:
        return []
    if n % 2 == 0:
        res = []
        for u in range(1,n//2 +1,2):
            res.append(u+1)
            res.append(u)
        return res
for u in range(int(input())):
    print (' '.join(list(map(str,f(int(input()))))))
