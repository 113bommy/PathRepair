n=int(input())
p=[int(input()) for _ in range(n)]
dp=[0]*(n+10)
for i in p:
  dp[i]=dp[i-1]+1
print(n-max(dp))