# ///////////////////////////////////////////////////////////////////////////
# //////////////////// PYTHON IS THE BEST ////////////////////////
# ///////////////////////////////////////////////////////////////////////////

import sys,os,io
import math 
from collections import defaultdict

from io import BytesIO, IOBase
from types import GeneratorType
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
def ii():
    return int(input())
def li():
    return list(map(int,input().split()))
# ///////////////////////////////////////////////////////////////////////////
# //////////////////// DO NOT TOUCH BEFORE THIS LINE ////////////////////////
# ///////////////////////////////////////////////////////////////////////////
if(os.path.exists('input.txt')):
    sys.stdin = open("input.txt","r") ; sys.stdout = open("output.txt","w") 
else:
    sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
    input = lambda: sys.stdin.readline().rstrip("\r\n")



def solve():
    n = ii()
    l = []
    for i in range(n):
        x = li()
        k = x[0]
        x = x[1:]
        # m = max(x)
        # ind = x.index(m)
        # l.append([m-ind+1,k])
        m = 0
        jj = 0
        for j in range(k):
            if x[j]-i+1>m:
                jj = j
            m = max(m , x[j]-j+1)
        l.append([m,k])
    # print(l)
    l = sorted(l,key = lambda x:x[1],reverse=True )
    l.sort()
    val = l[0][0]
    to = 0
    for i in range(len(l)-1):
        val+=l[i][1]
        if val+to<l[i+1][0]:
            to+=l[i+1][0]-val-to
        # val = l[i+1][1]
    print(l[0][0]+to)
    # l = sorted(l,key = lambda x:x[1],reverse=True)
    # l = sorted(l,key = lambda x:x[0])
    # ans = 0
    # val = l[0][0]
    # to = 0 
    # # print(l)
    # m = 0
    # last = l[0][1]
    # to = 0
    # for i in range(len(l)-1):
    #     last+=l[i][2]
    #     if last<l[i+1][0]:
    #         to+=l[i+1][0]-last 
    #         last+=l[i+1][0]-last 
    # print(val+to)




    

t = 1
t = ii()
for _ in range(t):
    solve()
