S = str(input())
mod = 10 ** 9 + 7
L = len(S)
d = "ABC".index
dp = [0 for _ in range(4)]
dp[0] = 1
for i in range(len(S)):
    if S[i] == '?':
        dp = [dp[0]*3, dp[1]*3+dp[0], dp[2]*3+dp[1], dp[3]*3+dp[2]]
        for j in range(4):
            dp[j] %= mod
    else:
        j = d(S[i])
        dp[j+1] += dp[j] % mod

print(dp[-1])