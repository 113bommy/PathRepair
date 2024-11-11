import sys
sys.setrecursionlimit(10 ** 7)

def dfs(s):
    if visited[s]:
        return
    visited[s] = 1
    for to in t[s]:
        if visited[to]:
            continue
        dfs(to)
    
N, M = map(int,input().split())
t = [[] for _ in range(N)]
visited = [0] * N
for _ in range(M):
    X, Y, Z = map(int,input().split())
    X -= 1
    Y -= 1
    t[X].append(Y)
    t[Y].append(X)
ans = 0
for i in range(1, N + 1):
    if visited[i]:
        continue
    ans += 1
    dfs(i)
print(ans)