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

from types import GeneratorType


def bootstrap(f, stack=[]):
    def wrappedfunc(*args, **kwargs):
        if stack:
            return f(*args, **kwargs)
        else:
            to = f(*args, **kwargs)
            while True:
                if type(to) is GeneratorType:
                    stack.append(to)
                    to = next(to)
                else:
                    stack.pop()
                    if not stack:
                        break
                    to = stack[-1].send(to)
            return to

    return wrappedfunc


def RL(): return map(int, sys.stdin.readline().rstrip().split())
def RLL(): return list(map(int, sys.stdin.readline().rstrip().split()))
def N(): return int(input())
def comb(n, m): return factorial(n) / (factorial(m) * factorial(n - m)) if n >= m else 0
def perm(n, m): return factorial(n) // (factorial(n - m)) if n >= m else 0
def mdis(x1, y1, x2, y2): return abs(x1 - x2) + abs(y1 - y2)
mod = 998244353
INF = float('inf')
from math import factorial
from collections import Counter, defaultdict, deque
from heapq import heapify, heappop, heappush

# ------------------------------
# f = open('./input.txt')
# sys.stdin = f

def main():
    n, k = RL()
    arr = [input() for _ in range(n)]

    dp = [[INF]*(n) for _ in range(n)]
    q = deque()

    pre = 0

    for i in range(n):
        for j in range(n):
            if i==0 and j==0:
                dp[0][0] = 1 if arr[0][0] != 'a' else 0
            elif i==0: dp[0][j] = dp[0][j-1] + (1 if arr[0][j]!='a' else 0 )
            elif j==0: dp[i][0] = dp[i-1][0] + (1 if arr[0][i]!='a' else 0)
            else: dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + (1 if arr[i][j]!='a' else 0)

            if dp[i][j]<=k:
                pre = max(pre, i+j+1)

    suf = 2*n-1-pre
    res = ['a']*pre + ['z']*suf
    vis = [[0]*n for _ in range(n)]

    q = []
    for i in range(n):
        for j in range(n):
            if dp[i][j]==k and i+j+1==pre:
                if i+1<n and vis[i+1][j]==0: q.append((i+1, j)); vis[i+1][j] = 1
                if j+1<n and vis[i][j+1]==0: q.append((i, j+1)); vis[i][j+1] = 1

    q.sort(key=lambda a: arr[a[0]][a[1]])

    if not q: q.append((0, 0))

    for i in range(pre, len(res)):
        newq = []
        res[i] = arr[q[0][0]][q[0][1]]

        for j in range(len(q)):
            now = arr[q[j][0]][q[j][1]]
            if now!=res[i]: break
            for nx, ny in [[1, 0], [0, 1]]:
                xx, yy = nx+q[j][0], ny+q[j][1]
                if xx<n and yy<n and vis[xx][yy]==0:
                    vis[xx][yy] = 1
                    while newq and arr[xx][yy]<arr[newq[-1][0]][newq[-1][1]]: newq.pop()
                    if not newq or arr[xx][yy]==arr[newq[-1][0]][newq[-1][1]]:
                        newq.append((xx, yy))
        q = newq
    print("".join(res))







if __name__ == "__main__":
    main()

