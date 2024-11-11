import sys
from collections import deque

read = sys.stdin.read
readline = sys.stdin.readline
readlines = sys.stdin.readlines
sys.setrecursionlimit(10 ** 9)
INF = 1 << 60


def main():
    MOD = 1000000007
    N, *AB = map(int, read().split())
    G = [[] for _ in range(N)]
    for a, b in zip(AB[::2], AB[1::2]):
        G[a - 1].append(b - 1)
        G[b - 1].append(a - 1)

    stack = deque([0])
    order = []
    prev = [0] * N
    prev[0] = -1
    while stack:
        v = stack.pop()
        order.append(v)
        for nv in G[v]:
            if nv != prev[v]:
                stack.append(nv)
                prev[nv] = v

    pow2 = [0] * (N + 1)
    pow2[0] = 1
    for i in range(N):
        pow2[i + 1] = pow2[i] * 2

    nodes = [1] * N
    numer = 0

    for v in reversed(order):
        if prev[v] != -1:
            nodes[prev[v]] += nodes[v]
        numer = (numer + pow2[N - 1] - 1 - (pow2[N - nodes[v]] - 1)) % MOD
        for nv in G[v]:
            if nv != prev[v]:
                numer = (numer - (pow2[nodes[nv]] - 1)) % MOD

    denom = pow2[N]
    ans = (numer * pow(denom, MOD - 2, MOD)) % MOD
    print(ans)
    return


if __name__ == '__main__':
    main()
