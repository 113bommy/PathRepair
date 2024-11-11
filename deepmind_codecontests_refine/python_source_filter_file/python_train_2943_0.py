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
# from collections import defaultdict as dc 
# from math import ceil,floor,sqrt
# from collections import Counter

n,m = RL()
dp = [[1]*m for _ in range(n)]
grid = []
for _ in range(n):
    grid.append(input())
if m==1 or n==1:
    print(m*n)
else:
    for i in range(1,n-1):
        for j in range(1,m-1):
            if grid[i][j]==grid[i+1][j] and grid[i][j]==grid[i-1][j] and grid[i][j]==grid[i][j+1] and grid[i][j]==grid[i][j-1]:
                dp[i][j] = min(dp[i-1][j],dp[i][j-1])+1

    for i in range(1,n-1):
        for j in range(m-2,0,-1):
            if grid[i][j]==grid[i+1][j] and grid[i][j]==grid[i-1][j] and grid[i][j]==grid[i][j+1] and grid[i][j]==grid[i][j-1]:
                dp[i][j] = min(min(dp[i-1][j],dp[i][j+1])+1,dp[i][j])

    for i in range(n-2,0,-1):
        for j in range(m-2,0,-1):
            if grid[i][j]==grid[i+1][j] and grid[i][j]==grid[i-1][j] and grid[i][j]==grid[i][j+1] and grid[i][j]==grid[i][j-1]:
                dp[i][j] = min(min(dp[i+1][j],dp[i][j+1])+1,dp[i][j])

    for i in range(n-2,0,-1):
        for j in range(1,m-1):
            if grid[i][j]==grid[i+1][j] and grid[i][j]==grid[i-1][j] and grid[i][j]==grid[i][j+1] and grid[i][j]==grid[i][j-1]:
                dp[i][j] = min(min(dp[i+1][j],dp[i][j-1])+1,dp[i][j])

print(sum(a for b in dp for a in b))











