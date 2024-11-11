# Repost
n=int(input())
from collections import defaultdict
graph=defaultdict(list)
visited={}
level={}
visited["polycarp"]=0
level["polycarp"]=1
for i in range(n):
    k,p,r=[j.lower() for j in input().split(' ')]
    graph[r].append(k)
    visited[k]=0
    level[k]=0
        
def dfs(graph,s):
    visited[s]=1
    for j in graph[s]:
        if not visited[j]:
            level[j]=1+level[s]
            dfs(graph,j)
dfs(graph,"polycarp")
print(max(level.values()))