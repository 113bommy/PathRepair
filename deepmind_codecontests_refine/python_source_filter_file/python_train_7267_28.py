from collections import Counter
n = int(input())
c = Counter(map(int, input().split()))
dp = [[[0]*(n+1) for _ in range(n+1)] for _ in range(n+1)]

for i in range(n+1):
    for j in range(n+1):
        for k in range(n+1):
            non_zero = i+j+k
            if non_zero == 0:
                continue
            dp[i][j][k] = n
            if 0 <= i-1 and j+1 <= n:
                dp[i][j][k] += dp[i-1][j+1][k]*i
            if 0 <= j-1 and k+1 <= n:
                dp[i][j][k] += dp[i][j-1][k+1]*j
            if 0 <= k-1:
                dp[i][j][k] += dp[i][j][k-1]*k
            dp[i][j][k] /= non_zero
print(dp[c[3]][c[2]][c[1]])