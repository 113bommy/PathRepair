import traceback
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

#####################################################################

import math
from collections import defaultdict as dfd, Counter
from functools import lru_cache
from itertools import accumulate

def geti():
    return int(input())

def gets():
    return input()

def getil():
    return list(map(int, input().split()))

def getsl():
    return input().split()

def getinps(s):
    inps = s.split()
    m = {'i': geti, 's': gets, 'il': getil, 'sl': getsl}
    if len(inps) == 1: return m[s]()
    return [m[k]() for k in inps]

def get2d(nrows, ncols, n=0):
    return [[n] * ncols for r in range(nrows)]

def get_acc(a):
    return list(accumulate(a))

def get_ncr(n, r):
    if n < r: return 0
    return math.factorial(n) // (math.factorial(r) * math.factorial(n-r))

def get_nc2(n):
    return n * (n-1) // 2
    
def get_npr(n, r):
    if n < r: return 0
    return math.factorial(n) // math.factorial(r) 

# sys.stdin = open('input.txt', 'r')
# sys.stdout = open('output.txt', 'w')

inf = float('inf')
mod = 10 ** 9 + 7




def main():
    (N, w), a = getinps('il il')
    minn, maxx = w, 0
    acc = get_acc(a)
    mn, mx = min(acc), max(acc)
    if mn >= 0:
        mn = 0
    else:
        mn = -mn
    if mx < 0:
        mx = w
    else:
        mx = w - mx
    if mn < 0 or mx > w or mn > mx: return 0
    return mx - mn + 1

try:
    ans = main()
    print(ans)

except Exception as e:
    print(e)
    traceback.print_exc()

