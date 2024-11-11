n,m,k,x,y=map(int,input().split())
t=n*m+(n-2)*m if n!=1 else m
b=k//t
g=[]
g.append([b for _ in range(m)])
for _ in range(n-2):
  g.append([2*b for _ in range(m)])
g.append([b for _ in range(m)])

r=k%t
mx=-1
mn=int(1e18)
for i in range(n):
  for j in range(m):
    if r>0:
      r-=1
      g[i][j]+=1
    mx=max(mx,g[i][j])
    mn=min(mn,g[i][j])
for i in range(n-2,0,-1):
  for j in range(m):
    if r>0:
      r-=1
      g[i][j]+=1
    mx=max(mx,g[i][j])
    mn=min(mn,g[i][j])
print(mx,mn,g[x-1][y-1])

