a,b=map(int,input().split())
c=[list(map(int,input().split())) for i in range(a)]
c.sort()
DP=[[0 for j in range(b+1)]for i in range(a)]
for i in range(c[0][0],b+1):
  DP[0][i]+=c[0][1]
for i in range(1,a):
  for j in range(b):
    if j<c[i][0]:
      DP[i][j]=DP[i-1][j]
    else:
      DP[i][j]=max(DP[i-1][j-c[i][0]]+c[i][1],DP[i-1][j])
  DP[i][b]=max(DP[i-1][b-1]+c[i][1],DP[i-1][b])
print(max(DP[-1]))
    
