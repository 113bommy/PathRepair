import collections
import math
import sys
from functools import reduce
import decimal

sys.setrecursionlimit(10 ** 9)
decimal.getcontext().rounding = decimal.ROUND_HALF_UP

graphDict = collections.defaultdict
queue = collections.deque()


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


def inp():
    return sys.stdin.readline().strip()


def map_inp(v_type):
    return map(v_type, inp().split())


def list_inp(v_type):
    return list(map_inp(v_type))


######################################## Solution ####################################

for _ in range(int(inp())):
    inp()
    n,k = map_inp(int)
    index = list_inp(int)
    value = list_inp(int)
    arr = [1000000007 for item in range(n)]
    for i, val in zip(index, value):
        arr[i - 1] = val

    for i in range(1, n):
        arr[i] = min(arr[i], arr[i - 1] + 1)
    for i in range(n - 2, -1, -1):
        arr[i] = min(arr[i], arr[i + 1] + 1)
    print(*arr)


