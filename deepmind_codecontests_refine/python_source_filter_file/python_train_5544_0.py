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

from math import factorial
from collections import Counter, defaultdict, deque
from heapq import heapify, heappop, heappush

def RL(): return map(int, sys.stdin.readline().rstrip().split())
def RLL(): return list(map(int, sys.stdin.readline().rstrip().split()))
def N(): return int(input())
def comb(n, m): return factorial(n) / (factorial(m) * factorial(n - m)) if n >= m else 0
def perm(n, m): return factorial(n) // (factorial(n - m)) if n >= m else 0
def mdis(x1, y1, x2, y2): return abs(x1 - x2) + abs(y1 - y2)
mod = 998244353
INF = float('inf')

# ------------------------------


def main():
    n, m, k = RL()

    gp = [[] for _ in range(n+1)]

    for _ in range(m):
        f, t = RL()
        gp[f].append(t)
        gp[t].append(f)


    vis = [0]*(n+1)
    cir = ()
    color = [0]*(n+1)
    pars = [-1]*(n+1)

    @bootstrap
    def dfs(node, par=-1, c=0):
        nonlocal cir
        vis[node] = 1
        color[node] = c
        pars[node] = par

        for nex in gp[node]:
            if nex==par: continue
            if vis[nex]==0:
                yield dfs(nex, node, c^1)
            elif vis[nex]==1:
                cir = (node, nex)
        vis[node] = 2
        yield None

    dfs(1)

    if cir==():
        # tree
        bl = color.count(1)
        wr = n-bl

        sel = 1
        if wr>bl: sel = 0

        res = []

        for i in range(1, n+1):
            if color[i]==sel:
                res.append(i)

        print(1)
        print(res[:(1+k)>>1])

    else:
        f, t = cir
        circle = [f]
        while circle[-1]!=t: circle.append(pars[circle[-1]])

        if len(circle)<=k:
            print(2)
            print(len(circle))
            print(*circle)
        else:
            res = []

            now = 0
            for _ in range((1+k)>>1):
                res.append(circle[now])
                now+=2
            print(1)
            print(*res)








if __name__ == "__main__":
    main()

