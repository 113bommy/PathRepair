n=int(input())
e=[[i] for i in range(n+1)]
for _ in range(n-1):
  a,b=map(int,input().split())
  e[a]+=[b]
  e[b]+=[a]
c=sorted(list(map(int,input().split())))
q=[1]
vis=[0]*(n+1)
ans=0
while q:
  now=q.pop()
  vis[now]=c.pop()
  for to in e[now]:
    if vis[to]:continue
    q+=[to]
print(sum(vis[2:]))
print(*vis[1:])