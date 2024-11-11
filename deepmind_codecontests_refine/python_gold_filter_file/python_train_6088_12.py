from collections import deque
from math import *
import heapq


d={}
n=int(input())
l=[]

for i in range(n):
    x=input()
    ind=[]
    for j in range(len(x)):
        if x[j]==" ":
            ind.append(j)
    
    name1=x[:ind[0]]
    name2=x[ind[1]+1:]
    l.append([name1.lower(),name2.lower()])
# print(l)
DAD=name1.lower()

visited={}
distance={}

for i in range(len(l)):
    if l[i][1] not in d:
        d[l[i][1]]=[l[i][0]]
    else:
        d[l[i][1]].append(l[i][0])
    visited[l[i][0]]=0
    visited[l[i][1]]=0

# visited={}
distance={}
for i in d:
    # visited[i]=0
    distance[i]=0
# visited[DAD]=0

def bfs(root):

    queue=deque([root])
    counter=0
    visited[root]=1
    distance[root]=0

    while queue:
        vertex=queue.popleft()
        if vertex not in d:
            continue
        # print(d[vertex])
        for neighbour in d[vertex]:
            if visited[neighbour]==0:
                distance[neighbour]=distance[vertex]+1
                visited[neighbour]=1
                queue.append(neighbour)
                # print(distance[neighbour])
    return
bfs("polycarp")
m=-1
for i in distance:
    if distance[i]>m:
        m=distance[i]
print(m+1)