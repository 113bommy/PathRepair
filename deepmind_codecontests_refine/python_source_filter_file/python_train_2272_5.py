N,C=map(int,input().split())
D=[list(map(int,input().split())) for i in range(C)]
c=[list(map(int,input().split())) for i in range(N)]
count=[[0]*C for i in range(3)]
for i in range(1,N+1):
  for j in range(1,N+1):
    count[(i+j)%3][c[i-1][j-1]-1]+=1
ans=1001
for i in range(C):
  for j in range(C):
    if i==j:
      continue
    for k in range(C):
      if i==k or j==k:
        continue
      tmp=0
      for x in range(C):
        tmp+=D[x][i]*count[0][x]+D[x][j]*count[1][x]+D[x][k]*count[2][x]
      if ans>tmp:
        ans=tmp
print(ans)