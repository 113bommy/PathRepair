import sys
sys.setrecursionlimit(10 ** 5+1)


def dfs(p):
    for edge in G[p]:
        if X[edge[0]] is not None:
            if X[edge[0]] - X[p] != edge[1]:
                print('No')
                exit()
        else:
            X[edge[0]] = X[p] + edge[1]
            dfs(edge[0])


N, M = map(int, input().split())
G = [[] for _ in range(N)]

for i in range(M):
    L, R, D = map(int, input().split())
    L -= 1
    R -= 1
    G[L].append((R, D))
    G[R].append((L, -D))

X = [None] * N
for i in range(N):
    if X[i] is None:
        X[i] = 0
        dfs(i)

print('Yes')
