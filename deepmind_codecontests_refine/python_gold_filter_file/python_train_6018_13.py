S=input()
l=len(S)
dp=[0 for i in range(13)] 
mod=10**9+7
 
if S[0]=='?':
  for i in range(10):
    dp[i]=1
else:
  dp[int(S[0])]=1
  
for i in range(1,l):
  count=[0 for i in range(13)]
  if S[i]=='?':
    for j in range(13):
      for k in range(10):
        count[(10*j+k)%13]+=dp[j]%mod
  else:
    for j in range(13):
      count[(10*j+int(S[i]))%13]+=dp[j]%mod
  dp=count
 
print(dp[5]%mod)