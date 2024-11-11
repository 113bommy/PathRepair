import bisect
import heapq
import math
import collections
import sys
import copy
from functools import reduce
import decimal
from io import BytesIO, IOBase
import os
import itertools
import functools
from types import GeneratorType

sys.setrecursionlimit(10 ** 9)
decimal.getcontext().rounding = decimal.ROUND_HALF_UP

graphDict = collections.defaultdict

queue = collections.deque


################## pypy deep recursion handling ##############
# Author = @pajenegod
def bootstrap(f, stack=[]):
    def wrappedfunc(*args, **kwargs):
        to = f(*args, **kwargs)
        if stack:
            return to
        else:
            while True:
                if type(to) is GeneratorType:
                    stack.append(to)
                    to = next(to)
                else:
                    stack.pop()
                    if not stack:
                        return to
                    to = stack[-1].send(to)

    return wrappedfunc


################## Graphs ###################
class Graphs:
    def __init__(self):
        self.graph = graphDict(set)

    def add_edge(self, u, v):
        self.graph[u].add(v)
        self.graph[v].add(u)

    def dfs_utility(self, nodes, visited_nodes, psf):
        global ans
        if len(visited_nodes.keys()) == n:
            ans = psf
            return
        visited_nodes[nodes] = None
        for neighbour in self.graph[nodes]:
            if neighbour not in visited_nodes:
                self.dfs_utility(neighbour, visited_nodes, psf + [neighbour])
        visited_nodes.pop(nodes)
        return

    def dfs(self, node):
        global ans
        Visited = collections.OrderedDict()
        self.dfs_utility(node, Visited, [node])

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


################### Tree Implementaion ##############
class Tree:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


def inorder(node, lis):
    if node:
        inorder(node.left, lis)
        lis.append(node.data)
        inorder(node.right, lis)
    return lis


def leaf_node_sum(root):
    if root is None:
        return 0
    if root.left is None and root.right is None:
        return root.data
    return leaf_node_sum(root.left) + leaf_node_sum(root.right)


def hight(root):
    if root is None:
        return -1
    if root.left is None and root.right is None:
        return 0
    return max(hight(root.left), hight(root.right)) + 1


#################################################

def rounding(n):
    return int(decimal.Decimal(f'{n}').to_integral_value())


def factors(n):
    return set(reduce(list.__add__,
                      ([i, n // i] for i in range(1, int(n ** 0.5) + 1) if n % i == 0), []))


def p_sum(array):
    return list(itertools.accumulate(array))


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

    def readline(self, **kwargs):
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
    arr = list_inp(int)
    temp = list(sorted(arr))
    count = 0
    for i in range(1, n):
        flag = 0
        for q, w in zip(temp, arr):
            if q != w:
                flag = 1
                break
        if flag == 0:
            break
        count += 1
        if i & 1:
            for j in range(1, n - 1, 2):
                if arr[j - 1] > arr[j]:
                    arr[j - 1], arr[j] = arr[j], arr[j - 1]
        else:
            for j in range(2, n, 2):
                if arr[j - 1] > arr[j]:
                    arr[j - 1], arr[j] = arr[j], arr[j - 1]

    print(count)
