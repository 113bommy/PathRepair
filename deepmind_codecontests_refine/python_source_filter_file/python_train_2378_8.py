import sys
sys.getrecursionlimit(1000000)

N, M = map(int, input().split())

G = [[] for i in range(N)]
for _ in range(M):
    Ai, Bi = map(int, input().split())
    G[Ai - 1].append(Bi - 1)
    G[Bi - 1].append(Ai - 1)

color = [0] * N
def dfs(v, c):
    '''
    頂点vをcで塗る　そこから深さ優先探索で交互に塗っていく
    '''
    color[v] = c
    for i in G[v]:
        if color[i] == c:
            return False
        if color[i] == 0 and not(dfs(i, -c)):
            return False
    return True

if dfs(0, 1):
    print(color.count(1) * color.count(-1) - M)
else:
    print(N * (N - 1) // 2 - M)
