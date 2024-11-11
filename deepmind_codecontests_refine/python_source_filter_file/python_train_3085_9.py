import sys
from collections import defaultdict
class Graph:
    def __init__(self):
        self.graph=defaultdict(list)
    def add(self,u,v):
        self.graph[u].append(v)
        self.graph[v].append(u)
    def dfs(self,v,vi,m):
        l1=[]
        l1.append(v)
        m=min(m,l[v-1])
        while len(l1)>0:
            c=l1.pop()
            if vi[c]==True:
                continue
            vi[c]=True
            m=min(m,l[c-1])
            for i in self.graph[c]:
                    l1.append(i)
                   # print(s)
        return best
g=Graph()
n,m=map(int,input().split())
l=list(map(int,input().split()))
for _ in range(m):
    k=input().split()
    g.add(int(k[0]),int(k[1]))
vi=[False]*(n+1)
k=0
for i in range(1,n+1):
    if vi[i]==False:
        best=l[i-1]
        k=k+g.dfs(i,vi,best)
print(k)
# g.DFS(l.index(min(l)))
