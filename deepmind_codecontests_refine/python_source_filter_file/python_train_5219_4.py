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
import math
import bisect
mod=998244353
# for _ in range(int(input())):
from collections import Counter
# sys.setrecursionlimit(10**6)
# dp=[[-1 for i in range(n+5)]for j in range(cap+5)]
# arr= list(map(int, input().split()))
#n,l= map(int, input().split())
# arr= list(map(int, input().split()))
# for _ in range(int(input())):
# n=int(input())
#for _ in range(int(input())):
import bisect
from heapq import *
from collections import  defaultdict
#n=int(input())
#n,m,s,d=map(int, input().split())
#arr = sorted(list(map(int, input().split())))
#ls=list(map(int, input().split()))
#d=defaultdict(list)
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


mod = 998244353


def power(base, exp):
    base %= mod
    if exp < 3:
        return (base ** exp) % mod
    half = power(base * base, exp // 2)
    return (half * base) % mod if exp % 2 == 1 else half % mod


def solve():
    n, m = map(int, input().split())
    graph = [[] for _ in range(n + 1)]
    count, visited = [0, 0], [-1 for _ in range(n + 1)]

    for _ in range(m):
        u, v = map(int, input().split())
        graph[u].append(v)
        graph[v].append(u)

    possible, ans = True, 1

    @bootstrap
    def dfs(node, par, parity):
        nonlocal possible, visited, graph, count
        if visited[node] != -1:
            possible = False if visited[node] != parity else possible
            yield None
        visited[node] = parity
        count[parity] += 1
        for child in graph[node]:
            if child != par:
                yield dfs(child, node, 1 - parity)
        yield

    # check for each node and update the answer
    for i in range(1, n + 1):
        if visited[i] == -1:
            count = [0, 0]
            dfs(i, -1, 1)
            ans *= (power(2, count[0]) + power(2, count[1])) % mod
            ans %= mod

    # print(ans if possible else 0)
    sys.stdout.write(str(ans) if possible else '0')
    sys.stdout.write('\n')


def main():
    tests = 1
    tests = int(input().strip())
    for test in range(tests):
        solve()