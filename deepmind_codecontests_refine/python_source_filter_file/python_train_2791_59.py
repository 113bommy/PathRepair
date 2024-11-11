n,k = map(int,input().split())
h = list(map(int,input().split()))
dp = [0] * n
for i in range(1,n):
  m = 10**5
  for j in range(min(i,k)):
    m = min(m,dp[i-j-1]+abs(h[i]-h[i-j-1]))
  dp[i] = m
print(dp[-1])