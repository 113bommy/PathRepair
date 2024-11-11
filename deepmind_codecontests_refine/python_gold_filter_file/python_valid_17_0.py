import bisect
import math
import collections
import sys
import copy
from functools import reduce
import decimal
from io import BytesIO, IOBase
import os

sys.setrecursionlimit(10 ** 9)
decimal.getcontext().rounding = decimal.ROUND_HALF_UP

graphDict = collections.defaultdict
queue = collections.deque


class Graphs:
    def __init__(self):
        self.graph = graphDict(list)

    def add_edge(self, u, v):
        self.graph[u].append(v)

    def dfs_utility(self, nodes, visited_nodes):
        visited_nodes.add(nodes)
        for neighbour in self.graph[nodes]:
            if neighbour not in visited_nodes:
                self.dfs_utility(neighbour, visited_nodes)
            else:
                return neighbour

    def dfs(self, node):
        Visited = set()
        self.dfs_utility(node, Visited)

    def bfs(self, node):
        visited = set()
        if node not in visited:
            queue.append(node)
            visited.add(node)
        while queue:
            parent = queue.popleft()
            print(parent)
            for item in self.graph[parent]:
                if item not in visited:
                    queue.append(item)
                    visited.add(item)


def rounding(n):
    return int(decimal.Decimal(f'{n}').to_integral_value())


def factors(n):
    return set(reduce(list.__add__,
                      ([i, n // i] for i in range(1, int(n ** 0.5) + 1) if n % i == 0)))


################################ <fast I/O> ###########################################
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


#############################################<I/O Region >##############################################


def inp():
    return sys.stdin.readline().strip()


def map_inp(v_type):
    return map(v_type, inp().split())


def list_inp(v_type):
    return list(map_inp(v_type))


######################################## Solution ####################################

for _ in range(int(inp())):
    n = int(inp())
    first = []
    second = []
    third = []
    fourth = []
    fifth = []
    for i in range(n):
        a, b, c, d, e = map_inp(int)
        first.append(a)
        second.append(b)
        third.append(c)
        fourth.append(d)
        fifth.append(e)
    ans = -1
    k = 0
    for i in range(1, n):
        if int(first[k] > first[i]) + int(second[k] > second[i]) + int(third[k] > third[i]) + int(
                fourth[k] > fourth[i]) + int(fifth[k] > fifth[i]) >= 3:
            k = i
    q = k
    k = n-1
    for i in range(n - 2, -1, -1):
        if int(first[k] > first[i]) + int(second[k] > second[i]) + int(third[k] > third[i]) + int(
                fourth[k] > fourth[i]) + int(fifth[k] > fifth[i]) >= 3:
            k = i
    if k == q:
        ans = k + 1
    print(ans)
