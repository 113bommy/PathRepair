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

    def dfs_utility(self, nodes, visited_nodes):
        visited_nodes.add(nodes)
        for neighbour in self.graph[nodes]:
            if neighbour not in visited_nodes:
                self.dfs_utility(neighbour, visited_nodes)

    def dfs(self, node):
        Visited = set()
        self.dfs_utility(i, Visited)

    def bfs(self, node, f_node):
        count = float("inf")
        visited = set()
        level = 0
        if node not in visited:
            queue.append([node, level])
            visited.add(node)
        flag = 0
        while queue:
            parent = queue.popleft()
            if parent[0] == f_node:
                flag = 1
                count = min(count, parent[1])
            level = parent[1] + 1
            for item in self.graph[parent[0]]:
                if item not in visited:
                    queue.append([item, level])
                    visited.add(item)
        return count if flag else -1
        return False

    def solve(self, in_degree):
        c = 0
        tracker = queue()
        ans = graphDict(lambda: 1)
        for ii in range(n):
            if in_degree[ii + 1] == 0:
                tracker.append(ii + 1)
        while tracker:
            node = tracker.popleft()
            c += 1
            for neighbour in self.graph[node]:
                in_degree[neighbour] -= 1
                if neighbour < node:
                    ans[neighbour] = max(ans[neighbour], ans[node] + 1)
                else:
                    ans[neighbour] = max(ans[neighbour], ans[node])
                if in_degree[neighbour] == 0:
                    tracker.append(neighbour)
        if c != n:
            return False
        else:
            return max(ans.values()) if len(ans.values()) > 0 else 1
        return "Send Help!!!!"


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


################## Union Find #######################
class UF:
    """An implementation of union find data structure.
    It uses weighted quick union by rank with path compression.
    """

    def __init__(self, N):
        """Initialize an empty union find object with N items.

        Args:
            N: Number of items in the union find object.
        """

        self._id = list(range(N))
        self._count = N
        self._rank = [0] * N

    def find(self, p):
        """Find the set identifier for the item p."""

        id = self._id
        while p != id[p]:
            p = id[p]  # Path compression using halving.
        return p

    def count(self):
        """Return the number of items."""

        return self._count

    def connected(self, p, q):
        """Check if the items p and q are on the same set or not."""

        return self.find(p) == self.find(q)

    def union(self, p, q):
        """Combine sets containing p and q into a single set."""

        id = self._id
        rank = self._rank

        i = self.find(p)
        j = self.find(q)
        if i == j:
            return

        self._count -= 1
        if rank[i] < rank[j]:
            id[i] = j
        elif rank[i] > rank[j]:
            id[j] = i
        else:
            id[j] = i
            rank[i] += 1

    def add_roads(self):
        return set(self._id)

    def __str__(self):
        """String representation of the union find object."""
        return " ".join([str(x) for x in self._id])

    def __repr__(self):
        """Representation of the union find object."""
        return "UF(" + str(self) + ")"


#################################################

def rounding(n):
    return int(decimal.Decimal(f'{n}').to_integral_value())


def factors(n):
    return set(reduce(list.__add__,
                      ([i, n // i] for i in range(1, int(n ** 0.5) + 1) if n % i == 0), []))


def p_sum(array):
    return list(itertools.accumulate(array))


def diophantine(a: int, b: int, c: int):
    d, x, y = extended_gcd(a, b)
    r = c // d
    return r * x, r * y


@bootstrap
def extended_gcd(a: int, b: int):
    if b == 0:
        d, x, y = a, 1, 0
    else:
        (d, p, q) = yield extended_gcd(b, a % b)
        x = q
        y = p - q * (a // b)

    yield d, x, y


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
def update(fen_tree, index):
    while index < len(fen_tree):
        fen_tree[index] += 1
        index += (index & -index)


def query(fen_tree, index):
    s = 0
    while index > 0:
        s += fen_tree[index]
        index -= (index & -index)
    return s


for _ in range(int(inp())):
    n, m, k = map_inp(int)
    if n == 1:
        if m > 0 or k <= 1:
            print("NO")
        else:
            print("YES")
    elif k <= 2:
        print("NO")
    else:
        if n - m > 1:
            print("NO")
        elif n - m == 1:
            if k <= 2 and n == 2:
                print("NO")
            elif k<=3 and n>3:
                print("NO")
            else:
                print("YES")
        elif m > (n * (n - 1)) // 2:
            print("NO")
        elif m < (n * (n - 1)) // 2:
            if k <= 2 and n == 2:
                print("NO")
            elif k <= 3 and n > 3:
                print("NO")
            else:
                print("YES")
        else:
            print("YES")
