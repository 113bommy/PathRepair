#!/usr/bin/env python3
import sys
from typing import List, Tuple, Dict
def debug(*args): print(*args, file=sys.stderr)
def exit(): sys.exit(0)


class UnionFind:
    def __init__(self, N):
        # type: (int) -> None
        self.N = N
        self.parent = list(range(N))  # type: List[int]

    def root(self, x):
        # type: (int) -> int
        path_to_root = []
        while self.parent[x] != x:
            path_to_root.append(x)
            x = self.parent[x]
        for node in path_to_root:
            self.parent[node] = x  # パス圧縮
        return x

    def same(self, x, y):
        # type: (int, int) -> bool
        return self.root(x) == self.root(y)

    def unite(self, x, y):
        # type: (int, int) -> None
        self.parent[self.root(x)] = self.root(y)

    def __str__(self):
        # type: () -> str
        groups = {}  # type: Dict[int, List[int]]
        for x in range(self.N):
            root = self.root(x)
            if root in groups.keys():
                groups[root].append(x)
            else:
                groups[root] = [x]
        result = ""
        for root in groups.keys():
            result += str(groups[root]) + "\n"
        return result


def kruskal(num_vertices, edges):
    # type: (int, List[Tuple[int, int, int]]) -> int
    """Kruscal法: 最小全域木を求める
    edgesについて破壊的なことに注意
    """
    total_weight = 0
    edges.sort(key=lambda e: e[2])
    u = UnionFind(num_vertices)
    for e in edges:
        x = e[0]
        y = e[1]
        weight = e[2]
        if u.same(x, y):
            continue
        u.unite(x, y)
        total_weight += weight
    return total_weight


N = int(input())
l = []
for i in range(N):
    l.append([i] + list(map(int, input().split())))

edges = []
sorted_x = sorted(l, key=lambda c: c[1])
sorted_y = sorted(l, key=lambda c: c[2])

for e in range(N-1):
    i0, x0, y0 = sorted_x[e]
    i1, x1, y1 = sorted_x[e+1]
    edges.append((i0, i1, x1-x0))

    i0, x0, y0 = sorted_y[e]
    i1, x1, y1 = sorted_y[e+1]
    edges.append((i0, i1, y1-y0))

print(kruskal(N, edges))
