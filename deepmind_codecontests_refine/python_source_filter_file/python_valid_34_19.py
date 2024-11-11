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
        
class RangeQuery:
    def __init__(self, data, func=min):
        self.func = func
        self._data = _data = [list(data)]
        i, n = 1, len(_data[0])
        while 2 * i <= n:
            prev = _data[-1]
            _data.append([func(prev[j], prev[j + i]) for j in range(n - 2 * i + 1)])
            i <<= 1
 
    def query(self, start, stop):
        """func of data[start, stop)"""
        depth = (stop - start).bit_length() - 1
        return self.func(self._data[depth][start], self._data[depth][stop - (1 << depth)])
 
    def __getitem__(self, idx):
        return self._data[0][idx]
 
 
def check(st, n, k):
    for i in range(n-k+1):
        g = st.query(i, i+k)
        if(g > 1):
            return True 
    return False
 
 
 
sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")
from collections import defaultdict,deque
from math import ceil,floor,sqrt,log2,gcd,pi
from heapq import heappush,heappop
from fractions import Fraction
from bisect import bisect_left,bisect,bisect_right
from itertools import combinations_with_replacement,permutations
import sys
abc='abcdefghijklmnopqrstuvwxyz'
ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ"

for _ in range(int(input())):
    n,k=map(int,input().split())
    arr=list(map(int,input().split()))
    mini=max(n-1000,0)
    ans=-float('inf')
    for i in range(mini-1,n):
        for j in range(i+1,n):
            ans=max(ans,(i+1)*(j+1)-(arr[i]|arr[j])*k)
    print(ans)
            