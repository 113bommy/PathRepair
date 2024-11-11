import os
import sys
from io import BytesIO, IOBase
import math
from decimal import Decimal
from decimal import *
from collections import defaultdict, deque
import heapq
from decimal import Decimal
getcontext().prec = 25
abcd='abcdefghijklmnopqrstuvwxyz'
MOD = pow(10, 9) + 7
BUFSIZE = 8192
from bisect import bisect_left, bisect_right
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

# n, k = map(int, input().split(" "))
# list(map(int, input().split(" ")))
# for _ in range(int(input())):


def dfs(i,j):
    val = l[i][j]

    s1 = set()
    s2 = set()
    q = deque()
    q.append([i,j])
    b= 0
    while q:
        x = q.popleft()
        if not v[x[0]][x[1]]:
            v[x[0]][x[1]]=True

            s2.add((x[0],x[1]))
            if l[x[0]+1][x[1]]==val:
                q.append([x[0]+1,x[1]])
                b+=1
            if l[x[0]][x[1]+1]==val:
                q.append([x[0],x[1]+1])
                b+=1
            if l[x[0]-1][x[1]]==val:
                q.append([x[0]-1,x[1]])
                b+=1
            if l[x[0]][x[1]-1]==val:
                q.append([x[0],x[1]-1])
                b+=1

    if len(s2)<=b//2:
        return True
    return False


n, m = map(int, input().split(" "))
l = []
l.append("="*(m+2))
for i in range(n):
    l.append("="+input()+"=")
l.append("="*(m+2))
v = [[False for i in range(m+2)] for j in range(n+2)]

ans = False
for i in range(n+2):
    for j in range(m+2):
        if l[i][j]=="=":
            v[i][j]=True
            continue
        if not v[i][j]:
            zz =dfs(i, j)
            if zz:
                ans=True
                break
    if ans:
        break
if ans:
    print("YES")
else:
    print("NO")