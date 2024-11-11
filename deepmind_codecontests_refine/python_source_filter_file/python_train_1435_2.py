from collections import deque

n,m=map(int,input().split())

graph=[[] for i in range(n)]

roomSign=[0]*n

for i in range(m):
    a,b=map(int,input().split())
    a-=1;b-=1
    graph[a].append(b)
    graph[b].append(a)

D=deque([0])

while D:
    v=D.popleft()
    for i in graph[v]:
        if roomSign[i] == 0:
          roomSign[i]=v
          D.append(i)

print("Yes")

for i in range(1,n):
    print(roomSign[i]+1)