from collections import defaultdict, deque
import sys
import io, os
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
def bfs(root,path):
    depth=[0]*(n+1)
    parent=[0]*(n+1)
    parent[root]=-1
    queue=deque([root])
    visited=set()
    visited.add(root)
    while queue:
        vertex=queue.popleft()
        for child in graph[vertex]:
            if child not in visited:
                if child in path:
                    depth[child]=0
                else:
                    depth[child]=depth[vertex]+1
                parent[child]=vertex
                visited.add(child)
                queue.append(child)
    onee,dist=1,0
    if len(path)>0:
        if onee!=1 and two!=1:
            onee=1
        elif onee!=2 and two!=2:
            onee=2
        else:
            onee=3
    for i in range(1,n+1):
        if depth[i]>=dist:
            onee=i
            dist=depth[i]
    return(onee,dist,parent)
def restore(a, s):
    res = set()
    while s != -1:
        res.add(s)
        s = a[s]
    return res
graph=defaultdict(list)
n=int(input())
for i in range(n-1):
    a,b=map(int,input().split())
    graph[a].append(b)
    graph[b].append(a)
one,dist,par=bfs(1,set())
two,dist,par=bfs(one,set())
ans=dist
#print(one,two,dist,par)
path=restore(par,two)
#print(path)
three,dist,par=bfs(one,path)
#print(three,dist,par)
print(ans+dist)
print(one,two,three)
