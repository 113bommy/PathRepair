from collections import deque
import sys
input = sys.stdin.readline
n,m,k = map(int,input().split())
sp = list(map(int,input().split()))
ab = [list(map(int,input().split())) for i in range(m)]
graph = [[] for i in range(n+1)]
for a,b in ab:
  graph[a].append(b)
  graph[b].append(a)
vf1 = [0 for i in range(n+1)]
vfn = [0 for i in range(n+1)]
def bfs(x,vf):
  que = deque([(x,1)])
  while que:
    x,cnt = que.popleft()
    vf[x] = cnt
    for y in graph[x]:
      if vf[y] == 0:
        que.append((y,cnt+1))
        vf[y] = cnt+1
bfs(1,vf1)
bfs(n,vfn)
ans = vf1[n]-1
ansls = []
for i in sp:
  ansls.append((vf1[i],vfn[i]))
ansls.sort(reverse=True)
l = len(ansls)
mn = ansls[0][1]
anstmp = []
for i in range(1,l):
  mn = min(mn,ansls[i][1])
  anstmp.append(ansls[i][0]+mn-1)
print(min(ans,max(anstmp)))