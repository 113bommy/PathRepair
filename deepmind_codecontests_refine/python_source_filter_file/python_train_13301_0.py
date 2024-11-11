r,c,k=map(int,input().split())
lst=[[0]*(c+1) for i in range(r+1)]
for i in range(k):
  s,t,u=map(int,input().split())
  lst[s][t]=u


dp1=[[0]*(c+1) for i in range(r+1)]
dp2=[[0]*(c+1) for i in range(r+1)]
dp3=[[0]*(c+1) for i in range(r+1)]

for i in range(1,r+1):
  for j in range(1,c+1):
    dp1[i][j]=max(dp1[i][j-1],dp1[i-1][j]+lst[i][j],dp2[i-1][j]+lst[i][j],dp3[i-1][j]+lst[i][j])
    dp2[i][j]=max(dp2[i][j-1],dp1[i][j-1]+lst[i][j])
    dp3[i][j]=max(dp3[i][j-1],dp2[i][j-1]+lst[i][j])

print(max(dp1[-1][-1],dp2[-1][-1],dp3[-1][-1]),0)
