import sys
sys.setrecursionlimit(10**7)
input = sys.stdin.readline

def dfs(v, color):
    colors[v] = color
    for to in g[v]:
        if colors[to] == color: return False
        if colors[to] == 0 and not dfs(to, -color):
            return False
    return True

def Washall_Floyd(d):
    for k in range(n):
        for i in range(n):
            for j in range(n):
                d[i][j] = min(d[i][j], d[i][k]+d[k][j])
    return d

n = int(input())
g = [[] for _ in range(n)]
f_inf =float('inf')
dist = [[f_inf]*n for _ in range(n)]
for i in range(n): dist[i][i]=0

for i in range(n):
    S = input()
    for j in range(n):
        if S[j] == '1':
            g[i].append(j)
            dist[i][j] = 1
            dist[j][i] = 1

colors = [0] * n
ans = -1
if not dfs(0, 1):
    print(ans)
else:
    Washall_Floyd(dist)
    for d in dist:
      tmp = max(d)
      ans = max(tmp, ans)
    print(ans+1)