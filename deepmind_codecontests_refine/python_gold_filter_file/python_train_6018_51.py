N = input()[::-1]
iv = 1
MOD = 10**9+7
dp = [0]*13
dp[0]=1
ls = [0]*13
for i in range(len(N)):
  x = N[i]
  
  if x=='?':
    for j in range(13):
      for h in range(10):
        ls[(h*iv+j)%13] += dp[j]
        
  else:
    x = int(x)
    for j in range(13):
      ls[(j+x*iv)%13]+=dp[j]
      
  for j in range(13):
    dp[j] = (ls[j]%MOD)
    ls[j]=0
  iv *= 10
  iv %= 13
print(dp[5])