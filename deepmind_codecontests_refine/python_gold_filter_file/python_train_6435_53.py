k = input()
d = int(input())
mod = 10**9 + 7

dp = [[[0] * d for i in range(2)] for j in range(len(k)+1)]
dp[0][0][0] = 1

for i in range(len(k)):
    for j in range(2):
        for m in range(d):
            if j == 1:
                for num in range(10):
                    dp[i+1][j][(m+num)%d] += dp[i][j][m]
                    dp[i+1][j][(m+num)%d] %= mod
            else:
                for num in range(int(k[i])+1):
                    if num != int(k[i]):
                        dp[i+1][1][(m+num)%d] += dp[i][j][m]
                        dp[i+1][1][(m+num)%d] %= mod
                    else:
                        dp[i+1][0][(m+num)%d] += dp[i][j][m]
                        dp[i + 1][0][(m + num) % d] %= mod

print((dp[len(k)][0][0] + dp[len(k)][1][0] - 1) % mod)
