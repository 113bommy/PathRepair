import sys
sys.setrecursionlimit(10 ** 8)

n, u, v = map(int, input().split())
to = [[] for _ in range(n + 1)]
for _ in range(n - 1):
    a, b = map(int, input().split())
    to[a].append(b)
    to[b].append(a)

def DFS(s, dist, to, d = 0, p = -1):
    dist[s] = d
    for v in to[s]:
        if v == p:
            continue
        DFS(v, dist, to, d + 1, s)
    
def calcDict(s, dist, to):
    DFS(s, dist, to)
    
distU = [0] * (n + 1)
distV = [0] * (n + 1)

calcDist(u, distU, to)
calcDist(v, distV, to)
ans = 0
for i in range(n + 1):
    if dictU[i] < dictV[i]:
        ans = max(ans, dictV[i])
print(ans - 1)