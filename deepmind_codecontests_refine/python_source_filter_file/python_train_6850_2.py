N,M=map(int,input().split())
list=[[] for i in range(3*N)]
for i in range(M):
  u,v=map(int,input().split())
  list[3*u-3].append(3*v-2)
  list[3*u-2].append(3*v-1)
  list[3*u-1].append(3*v-3)
s,t=map(int,input().split())
def bfs(a,b):
  visited=[-1 for i in range(3*N)]
  visited[a]=0
  h=[]
  h.append(a)
  while h:
    v=h.pop(0)
    for k in list[v]:
      if visited[k]==-1:
        visited[k]=visited[v]+1
        h.append(k)
  return visited[b]

print(bfs(3*s-3,3*t-1))