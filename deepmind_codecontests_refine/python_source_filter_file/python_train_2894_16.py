N,Q=map(int,input().split())
egde=[[] for _ in range(N)]
cnt=[0]*N
for _ in range(N-1):
  a,b=map(int,input().split())
  edge[a-1]+=(b-1),
  edge[b-1]+=(a-1),
for _ in range(Q):
  p,x=map(int,input().split())
  cnt[p-1]+=x
done=[False]*N
done[0]=True
stack=[0]
while stack:
  par=stack.pop()
  for child in edge[par]:
    if not done[child]:
      done[child]=True
      cnt[child]+=cnt[par]
      stack.append(child)
print(*cnt)