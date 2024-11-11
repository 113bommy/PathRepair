n = int(input())
a = list(map(int,input().split()))
dp = [0] * n
dp[0] = 1000
for i in range(1, n):
  dp[i] = max(dp[i-1], dp[i-1] // a[i-1] * a[i] + dp[i-1] % a[i-1])
print(dp[i-1])