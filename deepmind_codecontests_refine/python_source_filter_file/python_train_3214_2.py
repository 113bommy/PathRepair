N, C = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
mod = 10**9+7

acc = [[0] for _ in range(401)]
for i in range(401):
    for j in range(1, C+2):
        acc[i].append(((acc[i][-1] + pow(j, i, mod)) % mod))

dp = [[0 for _ in range(C+1)] for _ in range(N+1)]
dp[0][0] = 1
for i in range(N):
    for candy_cur in range(C+1):
        for candy_plus in range(C - candy_cur+1):
            dp[i+1][candy_cur + candy_plus] = (dp[i+1][candy_cur + candy_plus] + (dp[i][candy_cur]\
                                               * ((acc[candy_plus][B[i]] - acc[candy_plus][A[i]-1])%mod)%mod)) % mod

print(dp[-1][C])
