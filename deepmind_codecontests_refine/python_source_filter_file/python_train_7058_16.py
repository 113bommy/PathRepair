n = int(input())
link = [[] for _ in range(n)]
for i in range(n-1):
    a,b = list(map(int,input().split()))
    link[a-1].append(b-1)
    link[b-1].append(a-1)
c=list(map(int, input().split()))
c.sort(reverse=True)
print(sum(c)-c[-1])

from collections import deque
Q = deque()
Q.append(0)
visited=[-1]*n
visited[0]=0

ind=1
while Q:
    now = Q.popleft()
    for nxt in link[now]:
        if visited[nxt]!=-1:
            continue
        visited[nxt]=ind
        ind+=1
        Q.append(nxt)
for i in visited:
    print(c[i],end=" ")