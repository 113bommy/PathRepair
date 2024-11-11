n=int(input())
tr=[[] for _ in range(n)]
for _ in range(n-1):
    x,y=map(int,input().split())
    x,y=x-1,y-1
    tr[x].append(y)
    tr[y].append(x)
from collections import deque
seen=[-1]*n
todo=deque([0])
while todo:
    v=todo.popleft()
    seen[v]=1
    for nv in tr[v]:
        if seen[nv]==-1:
            todo.append(nv)
v0=v
seen=[-1]*n
todo=deque([v])
seen[v]=0
while todo:
    v=todo.popleft()
    for nv in tr[v]:
        if seen[nv]==-1:
            todo.append(nv)
            seen[nv]=seen[v]+1
c=seen[v]
c+=1
if c%3==2:
    print('Second')
else:
    print('First')
