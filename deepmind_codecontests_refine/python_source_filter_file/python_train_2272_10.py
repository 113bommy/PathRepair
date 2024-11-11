n,c=map(int,input().split())
d=[list(map(int,input().split()))for _ in range(c)]
l=[[i for i in[0]*c]for _ in range(3)]
for i in range(n):
  t=list(map(int,input().split()))
  for j in range(n):
    l[(i+j)%3][t[j]-1]+=1
c=10**18
for i in range(c):
  for j in range(c):
    for k in range(c):
      if i==j or j==k or k==i:continue
      c=min(c,sum(d[x][i]*l[0][x]+d[x][j]*l[1][x]+d[x][k]*l[2][x]for x in range(c)))
print(c)