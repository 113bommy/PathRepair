import sys
sys.setrecursionlimit(10*9)

def dfs(now):
    for to,dis in G[now]:
        if color[to] == -1:
            color[to] = (color[now] + dis) % 2
            dfs(to)

N = int(input())
G = [[] for _ in range(N)]
color = [-1] * N
color[0] = 0 #偶数=0

for i in range(N-1):
    a,b,c = map(int,input().split())
    a -= 1
    b -= 1
    G[a].append([b,c%2])
    G[b].append([a,c%2])

#print(G)    
dfs(0)
print(*color,sep="\n")