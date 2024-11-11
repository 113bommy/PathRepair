import array
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

#
# sys.setrecursionlimit(10 ** 9)
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

    def dfs_utility(self, nodes, visited_nodes, colors, parity, level):
        global count
        if nodes == 1:
            colors[nodes] = -1
        else:
            if len(self.graph[nodes]) == 1 and parity % 2 == 0:
                if q == 1:
                    colors[nodes] = 1
                else:
                    colors[nodes] = -1
                    count += 1
            else:
                if parity % 2 == 0:
                    colors[nodes] = -1
                else:
                    colors[nodes] = 1
        visited_nodes.add(nodes)
        for neighbour in self.graph[nodes]:
            new_level = level + 1
            if neighbour not in visited_nodes:
                self.dfs_utility(neighbour, visited_nodes, colors, level - 1, new_level)

    def dfs(self, node):
        Visited = set()
        color = collections.defaultdict()
        self.dfs_utility(node, Visited, color, 0, 0)
        return color

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
class UnionFind():
    parents = []
    sizes = []
    count = 0

    def __init__(self, n):
        self.count = n
        self.parents = [i for i in range(n)]
        self.sizes = [1 for i in range(n)]

    def find(self, i):
        if self.parents[i] == i:
            return i
        else:
            self.parents[i] = self.find(self.parents[i])
            return self.parents[i]

    def unite(self, i, j):
        root_i = self.find(i)
        root_j = self.find(j)
        if root_i == root_j:
            return
        elif root_i < root_j:
            self.parents[root_j] = root_i
            self.sizes[root_i] += self.sizes[root_j]
        else:
            self.parents[root_i] = root_j
            self.sizes[root_j] += self.sizes[root_i]

    def same(self, i, j):
        return self.find(i) == self.find(j)

    def size(self, i):
        return self.sizes[self.find(i)]

    def group_count(self):
        return len(set(self.find(i) for i in range(self.count)))

    def answer(self, extra, p, q):
        dic = collections.Counter()
        for q in range(n):
            dic[self.find(q)] = self.size(q)
        hq = list(dic.values())
        heapq._heapify_max(hq)
        ans = -1
        for z in range(extra + 1):
            if hq:
                ans += heapq._heappop_max(hq)
            else:
                break
        return ans


#################################################

def rounding(n):
    return int(decimal.Decimal(f'{n}').to_integral_value())


def factors(n):
    return set(reduce(list.__add__,
                      ([i, n // i] for i in range(1, int(n ** 0.5) + 1) if n % i == 0)))


def p_sum(array):
    return list(itertools.accumulate(array))


def base_change(nn, bb):
    if nn == 0:
        return [0]
    digits = []
    while nn:
        digits.append(int(nn % bb))
        nn //= bb
    return digits[::-1]


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


######################################################################################

'''
Knowledge and awareness are vague, and perhaps better called illusions.
Everyone lives within their own subjective interpretation.
                                                            ~Uchiha Itachi
'''

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


def interactive():
    return sys.stdout.flush()


######################################## Solution ####################################

def valid(x):
    temp = list.copy(arr)
    flag = 1
    for i in range(n - 2):
        if flag:
            if arr[i] < x:
                return False
            div, rem = divmod(arr[i] - x, 3)
            temp[i] = x + rem
            temp[i + 1] += div
            temp[i + 2] += 2 * div
            flag = 0
        else:
            if temp[i] < x:
                return False
            div, rem = divmod(arr[i], 3)
            if temp[i] - (arr[i] - rem) >= x:
                temp[i] -= (arr[i] - rem)
                temp[i + 1] += div
                temp[i + 2] += 2 * div
            else:
                f = 0
                l = arr[i]
                while f + 1 < l:
                    m = (f + l) // 2
                    q, r = divmod(m, 3)
                    if temp[i] - (m - r) >= x:
                        f = m
                    else:
                        l = m
                temp[i] -= f + f % 3
                temp[i + 1] += f // 3
                temp[i + 2] += 2 * (f // 3)

    if min(temp) >= x:
        return True
    else:
        return False


for _ in range(int(inp())):
    n = int(inp())
    arr = list_inp(int)
    arr.reverse()
    start = 1
    end = 10 ** 9
    while start + 1 < end:
        mid = (start + end) // 2
        if valid(mid):
            start = mid
        else:
            end = mid
    print(start)
