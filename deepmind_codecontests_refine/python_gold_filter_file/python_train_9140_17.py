N = int(input())
ps = map(float, input().split())

dp = [0] * (N+1)
dp[0] = 1
for p in ps:
    pp = 1 - p
    for j in reversed(range(N+1)):
        dp[j] = dp[j]*pp + dp[j-1]*p

print(sum(dp[(N+1)//2:]))
