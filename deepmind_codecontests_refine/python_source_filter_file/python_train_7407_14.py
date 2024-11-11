from collections import defaultdict
class Graph:
    def __init__(self):
        self.graph = defaultdict(list)
    
    def addEdge(self,u,v):
        self.graph[u].append(v)

    def dfs(self,visited,v,num,group):
        visited[v] = True
        group[v] = num
        for i in self.graph[v]:
            if(visited[i]==False):
                self.dfs(visited,i,num+1,group)

    def DFSUtil(self,root,V):
        visited = [False]*(V+1)
        group = [-1]*(V+1)
        num = 1
        for i in range(1,V+1):
            if(root[i]==True):
                self.dfs(visited,i,num,group)
        return max(group)

n = int(input())
root = [True]*(n+1)
g = Graph()
for i in range(1,n+1):
    k = int(input())
    if(k!=-1):
        g.addEdge(i,k)
        root[k]=False
print(g.DFSUtil(root,n))