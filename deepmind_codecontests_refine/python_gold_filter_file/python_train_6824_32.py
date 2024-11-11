from collections import Counter
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
# from collections import Counter
# from fractions import Fraction
# s=iter(input())
# from collections import deque
# n=int(input())
# n,k=map(int,input().split())
# arr=list(map(int,input().split()))
# ls=list(map(int,input().split()))
from bisect import bisect_right
import math
n=int(input())
    #n, k = map(int, input().split())
c = list(map(int, input().split()))
    #g=[[] for i in range(n)]
f=0
n=len(c)
pre=input()
dp=[[math.inf]*2 for i in range(n)]
dp[0][0]=0
dp[0][1]=c[0]
for i in range(1,n):
    s = input()
    if s >= pre:
        dp[i][0] = min(dp[i][0], dp[i - 1][0])
    if s >= pre[::-1]:
        dp[i][0] = min(dp[i][0], dp[i - 1][1])
    if s[::-1] >= pre:
        dp[i][1] = min(dp[i][1], dp[i - 1][0] + c[i])
    if s[::-1] >= pre[::-1]:
        dp[i][1] = min(dp[i][1], dp[i - 1][1]+c[i])
    pre = s
    if dp[i][0] >=math.inf and dp[i][1] >=math.inf:
        f = 1
        break
if f==1:
    print(-1)
else:
    print(min(dp[n-1][0],dp[n-1][1]))



