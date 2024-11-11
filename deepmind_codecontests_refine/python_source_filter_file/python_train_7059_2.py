N, M = map(int, input().split())
mod = 10**9 + 7
dp = [0]*((N+1)*(M+1))
dp[1] = 1
for i in range(1, N+1):
    s = input().strip()
    for j in range(1, M+1):
        if s[j-1] == ".":
            dp[i*(M+1)+j] = dp[(i-1)*(M+1) + j] + dp[i*(M+1) + j-1]
print(dp[N*(M+1)+M])
