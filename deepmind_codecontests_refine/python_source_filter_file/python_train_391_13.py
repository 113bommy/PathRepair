import sys
input=sys.stdin.readline
n,u,v=map(int,input().split())
Edge=[[] for i in range(n)]
for i in range(n-1):
  a,b=map(int,input().split())
  Edge[a-1].append(b-1)
  Edge[b-1].append(a-1)


from collections import deque

def BFS(s):
  dist=[-1]*n
  que=deque([s-1])
  dist[s-1]=0
  while que:
    v=que.popleft()
    d=dist[v]
    for w in Edge[v]:
      if dist[w]>-1:
        continue
      dist[w]=d+1
      que.append(w)
  return dist

U_d,V_d=BFS(u),BFS(v)
ans=0
for i in range(n):
  if U_d[i]<V_d[i]:
    ans=max(ans,U_d[i])
print(ans)
