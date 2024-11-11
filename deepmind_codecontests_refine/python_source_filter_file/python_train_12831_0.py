import sys
input=sys.stdin.readline
import collections
from collections import defaultdict
n=int(input())
def bfs(root):
    visited=[0]*(n+1)
    queue=collections.deque([root])
    visited[root]=1
    while queue:
        vertex=queue.popleft()
        for i in graph[vertex]:
            if visited[i]==0:
                depth[i]=depth[vertex]+1
                queue.append(i)
                visited[i]=1
graph=defaultdict(list)                            
for i in range(n-1):
    u,v=map(int,input().split())
    graph[u-1].append(v-1)
    graph[v-1].append(u-1)
depth=[0]*(n+1)
depth[0]=0
bfs(0)
odd,even=0,0
for i in depth:
    if i&1:
        odd+=1
    else:
        even+=1
print(min(odd,even)-1)
               
          
          
               
     
