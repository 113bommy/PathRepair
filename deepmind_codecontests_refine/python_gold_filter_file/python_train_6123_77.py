#!/usr/bin/env python3
import sys
from collections import defaultdict
sys.setrecursionlimit(10**8)
INF = float("inf")

MOD = 1000000007  # type: int


class Graph(object):
    def __init__(self, N):
        self.N = N
        self.E = defaultdict(list)

    def add_edge(self, f, t, w=1):
        self.E[f].append((t, w))
        self.E[t].append((f, w))


def solve(N: int, x: "List[int]", y: "List[int]"):

    g = Graph(N)
    for xx, yy in zip(x, y):
        g.add_edge(xx-1, yy-1)

    white = [-1]*N
    black = [-1]*N

    def rec(node, pre):
        if white[node] > 0:
            return white[node], black[node]

        # nodeを黒と塗る場合
        bbb = 1
        www = 1
        for t, _ in g.E[node]:
            if t != pre:
                w, b = rec(t, node)
                bbb *= w
                bbb %= MOD
                www *= (w+b) % MOD
                www %= MOD
        black[node] = bbb % MOD
        white[node] = www % MOD
        return white[node], black[node]

    w, b = rec(0, -1)
    print((w+b) % MOD)
    return


def main():

    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    N = int(next(tokens))  # type: int
    x = [int()] * (N - 1)  # type: "List[int]"
    y = [int()] * (N - 1)  # type: "List[int]"
    for i in range(N - 1):
        x[i] = int(next(tokens))
        y[i] = int(next(tokens))
    solve(N, x, y)


if __name__ == '__main__':
    main()
