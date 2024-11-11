n=int(input())
edges=[[] for i in range(n)]
import sys

sys.setrecursionlimit(10**10)
for i in range(n-1):
    a,s,w=map(int,input().split())
    edges[a-1].append([s-1,w]);edges[s-1].append([a-1,w])
colors=[-1]*n
colors[0]=1
def dfs(now):
    for to,cost in edges[now]:
        if colors[to]==-1:
            colors[to]=(cost+colors[now])%2
            dfs(to)

dfs(0)
print(*colors,sep="\n")