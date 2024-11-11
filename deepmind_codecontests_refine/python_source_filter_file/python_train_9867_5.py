a,b,c,d=map(int,input().split())
mod=998244353

dp1=[[0]*(d+1) for _ in range(c+1)]
dp2=[[0]*(d+1) for _ in range(c+1)]

for i in range(b+1,d+1):
  if a==1:
    dp1[a][i]=1 if i==b+1 else 0
    dp2[a][i]=0 if i==b+1 else 1
  else:
    dp1[a][i]=(pow(a-1,i-b-1,mod)*(i-b))%mod
    dp2[a][i]=(pow(a,i-b,mod)-dp1[a][i])%mod
for i in range(a+1,c+1):
  dp1[i][b]=pow(b,i-a,mod)
  dp2[i][b]=0
dp2[a][b]=1
for i in range(a+1,c+1):
  for j in range(b+1,d+1):
    dp1[i][j]=(j*(dp1[i-1][j]+dp2[i-1][j]))%mod
    dp2[i][j]=(dp1[i][j-1]+dp2[i][j-1]*i)%mod
print(dp1[c][d]+dp2[c][d])
"""
print('dp1')
for x in dp1:
  print(x)
print('dp2')
for x in dp2:
  print(x)
"""