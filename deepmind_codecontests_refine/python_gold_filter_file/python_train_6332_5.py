n,m=map(int,input().split())
f=lambda x:int(x)-1
p=list(map(f,input().split()))
par=[j for j in range(n)]
def find(x):
  if x==par[x]:
    return x
  else:
    par[x]=find(par[x])
    return par[x]
 
def union(a,b):
  ra=find(a)
  rb=find(b)
  if ra!=rb:
    par[ra]=par[rb]
 
for i in range(m):
  v,w=map(f,input().split())
  union(v,w)
 
ans=0
for j in range(n):
  if find(j)==find(p[j]):
    ans+=1
print(ans)