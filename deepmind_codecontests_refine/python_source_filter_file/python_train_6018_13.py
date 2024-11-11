def f(i,k):
  for j in range(13):
    dp[i+1][(j*10+k)%13]+=dp[i][j]
    dp[i+1][(j*10+k)%13]%=mod
  
mod=10**9+7
s=input()
n=len(s)
dp=[[0]*13 for i in range(10**5)]
dp[0][0]=mul=1

for i in range(n):
  if s[i]=='?':
    for k in range(10):
      f(i,k)
  else:
    f(i,int(s[i]))
  
print(dp[n][5]%mod)
