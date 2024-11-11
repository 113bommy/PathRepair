S = input()

MOD = 10 ** 9 + 7
N = len(S)
dp = [[0] * 4 for _ in range(N + 1)]
dp[-1][-1] = 1

for i in reversed(range(N)):
    m = 3 if S[i] == '?' else 1
    for j in reversed(range(3)):
        dp[i][j] = m * dp[i + 1][j]
        if S[i] == '?' or S[i] == 'ABC'[j]:
            dp[i][j] += dp[i + 1][j + 1]
        dp[i][j] %= MOD
    
    # j == 3
    dp[i][3] = m * dp[i + 1][3] % MOD
            
print(dp[0][0] % MOD)

