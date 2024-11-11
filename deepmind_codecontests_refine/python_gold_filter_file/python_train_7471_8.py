S = int(input())
div = 10 ** 9 + 7
dp = [0, 0, 0, 1, 1, 1]
for i in range(6, S + 1):
    dp.append((dp[i-3]+dp[i-1]) % div)
print(dp[S])