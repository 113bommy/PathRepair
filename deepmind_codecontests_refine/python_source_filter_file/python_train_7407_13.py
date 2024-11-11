from collections import defaultdict
graph = defaultdict(list)

def addEdge(u,v):
    graph[u].append(v)

n = int(input())
arr = []
for i in range(n):
    arr.append(int(input()))
for i in range(n):
    if arr[i]!=-1:
        addEdge(i+1,arr[i])


def DFSUtil(v,visited,stack):
    visited.append(v)
    stack.append(v)
    for node in graph[v]:
        if node not in visited:
            DFSUtil(node,visited,stack)
    return stack


cc = []
for i in range(1,n+1):
    visited=[]
    if i in graph:
        stack = []
        if i not in visited:
            cc.append(DFSUtil(i,visited,stack))


cc.sort(reverse=True,key=lambda arr:len(arr))
if len(cc)<=1:
    print(1)
else:
    print(len(cc[0]))
