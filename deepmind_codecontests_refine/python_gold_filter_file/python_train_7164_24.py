n,m,q=map(int,input().split())
x=[[0]*(n+1) for i in range(n+1)]
c=[[0]*(n+1) for i in range(n+1)]
for i in range(m):
  l,r=map(int,input().split())
  x[l][r]+=1
for i in range(1,n+1):
  for j in range(1,n+1):
    c[i][j]=c[i][j-1]+x[i][j]
for i in range(q):
  p,q=map(int,input().split())
  s=0
  for j in range(p,q+1):
    s+=c[j][q]-c[j][p-1]
  print(s)