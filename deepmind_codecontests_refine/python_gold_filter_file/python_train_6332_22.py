n,m=map(int,input().split())
p=list(map(int,input().split()))
par=[i for i in range(n)]
 
def find(x):
  if par[x]==x:
    return par[x]
  else:
    par[x]=find(par[x])
    return par[x]
 
def union(x,y):
  fx=find(x)
  fy=find(y)
  if fx!=fy:
    par[fx]=fy
 
f=lambda x:int(x)-1
for mm in range(m):
  x,y=map(f,input().split())
  union(x,y)
 
ans=0
for i in range(n):
  if find(p[i]-1)==find(i):
    ans+=1
print(ans)