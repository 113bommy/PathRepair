n = int(input())
p = list(map(float,input().split()))
dp = [0]*(n+1)
dp[0] = 1
for i in range(1,n+1):
  for j in range(n,0,-1):
    dp[j] += dp[j-1]*p[i-1]
    dp[j-1] -= dp[j-1]*p[i-1]
ans = 0
for i in range(n//2+1,n+1):
  ans += dp[i]
print(ans)