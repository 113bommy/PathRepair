#!/usr/bin/env python3
import sys

sys.setrecursionlimit(10 ** 8)
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
MOD = 1000000007  # type: int

N = int(readline())
adj = [[] for _ in range(N)]
for _ in range(N - 1):
    x, y = [int(a) - 1 for a in readline().split()]
    adj[x].append(y)
    adj[y].append(x)


def solve(node, parent):
    w, b = 1, 1
    for nxt in adj[node]:
        if nxt != parent:
            w1, b1 = solve(nxt, node)
            w *= w1 + b1
            w %= MOD
            b *= w1
            b %= MOD
    return w, b


if __name__ == "__main__":
    print(sum(solve(0, -1)))
