n,m,q=map(int,input().split())
d=[[0]*(n+1) for _ in range(n+1)]

for mm in range(m):
  l,r=map(int,input().split())
  d[l][r]+=1

for i in range(n):
  for j in range(n+1):
    d[i+1][j]+=d[i][j]

for j in range(n+1):
  for i in range(n):
    d[j][i+1]=d[j][i]
    
for qq in range(q):
  x,y=map(int,input().split())
  print(d[y][y]-d[y][x-1]-d[x-1][y]+d[x-1][x-1])