n = int(input())
mod = 10**9+7
dp = [0]*(n+1)
dp[0] = 1
for i in range(n):
    nx = [0]*(n+1)
    s = str(input())
    if s == 'f':
        nx[0] = 0
        for j in range(1, n+1):
            nx[j] = dp[j-1]
            nx[j] %= mod
    else:
        nx[n] = dp[n]
        for j in reversed(range(n)):
            nx[j] = nx[j+1]
            nx[j] += dp[j]
            nx[j] %= mod
    if i != n-1:
        dp = nx
print(sum(dp))
