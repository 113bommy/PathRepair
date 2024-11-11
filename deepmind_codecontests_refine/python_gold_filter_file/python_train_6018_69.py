mod=10**9+7
r=[[(j-k)*9%13 for j in range(10)] for k in range(13)]
dp=[1]+[0]*12
for c in input():
  dp = [sum(dp[j] for j in k)%mod for k in r] if c>'9' else [dp[(int(c)-k)*9%13] for k in range(13)]
print(dp[5])