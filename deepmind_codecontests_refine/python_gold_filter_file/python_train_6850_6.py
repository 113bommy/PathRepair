from collections import deque
import sys
n,m=map(int,input().split())
g=[[] for _ in range(3*n)]
for _ in range(m):
  u,v=map(int, sys.stdin.readline().split())
  u-=1
  v-=1
  g[u].append(n+v)
  g[u+n].append(v+2*n)
  g[u+2*n].append(v)
s,t=map(int,input().split())
s-=1
t-=1
vit=set([s])
ans=[-3]*3*n
q=deque([s])
ans[s]=0
while q:
  a=q.popleft()
  for b in g[a]:
    if b in vit:
      continue
    vit.add(b)
    ans[b]=ans[a]+1 
    q.append(b)
print(ans[t]//3)