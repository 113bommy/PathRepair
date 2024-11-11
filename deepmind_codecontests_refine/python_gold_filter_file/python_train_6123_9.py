import sys

input = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)
int1 = lambda x: int(x) - 1
MOD = 10 ** 9 + 7

N = int(input())
T = [[] for _ in range(N)]

for _ in range(N - 1):
    a, b = map(int1, input().split())
    T[a].append(b)
    T[b].append(a)


def dfs(x, parent):
    b, w = 1, 1
    for n in T[x]:
        if n == parent:
            continue
        nb, nw = dfs(n, x)
        b *= nw
        w *= (nw + nb)
    b %= MOD
    w %= MOD
    return b, w


b, w = dfs(0, 0)
print((b + w) % MOD)
