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

sys.stdin = IOWrapper(sys.stdin)
# sys.stdout = IOWrapper(sys.stdout)
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

def get_ncr(n, r, mod=10**9+7):
    num = den = 1
    r = min(r, n-r)
    for i in range(r):
        num = (num * (n - i)) % mod
        den = (den * (i + 1)) % mod
    return num * pow(den, mod - 2, mod) % mod

def get_nc2(n):
    return n * (n-1) // 2
    
def get_npr(n, r):
    if n < r: return 0
    return math.factorial(n) // math.factorial(r) 

def put(a):
    return ' '.join(map(str, a))

# sys.stdin = open('input.txt', 'r')
# sys.stdout = open('output.txt', 'w')

inf = float('inf')
mod = 10 ** 9 + 7




def main():
    N = geti()
    s = 'a' * (N//2)
    s += 'b'
    s += 'a' * (N//2-1)
    s += 'c' if N&1 and N!=1 else ''
    return s

try:
    Test = geti()
    answers = []
    for _ in range(Test):
        ans = main()
        ans = str(ans)
        answers.append(ans)
    print('\n'.join(answers))

except Exception as e:
    print(e)
    traceback.print_exc()