N, M = map(int, input().split())
S = list(map(int, input().split()))
T = list(map(int, input().split()))
dp = [1] * (M+1)
dpleft = [0] * (M)
MOD = 10 ** 9 + 7
ndp = [1] * (M+1)
for n in range(N):
    for m in range(M):
        if S[n] == T[m]:
            ndp[m+1] = ndp[m] + dp[m+1])
            dpleft[m] = dp[m+1]
        else:
            ndp[m+1] = ndp[m] + dpleft[m]
    dp = ndp
print(dp[-1] % MOD)