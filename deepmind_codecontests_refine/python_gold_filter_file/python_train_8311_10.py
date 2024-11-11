import sys
sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline
N = int(input())
G = [[] for i in range(N + 1)]
for i in range(1, N):
    a = int(input())
    G[a - 1].append(i)


def dfs(v):
    if len(G[v]) == 0:
        return 0
    D = []
    for w in G[v]:
        D.append(dfs(w))

    D = sorted(D, reverse=True)

    num = 0
    for i in range(len(D)):
        num = max(num, D[i] + i + 1)

    return num


print(dfs(0))