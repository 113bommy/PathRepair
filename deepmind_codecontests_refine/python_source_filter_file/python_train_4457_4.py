mod = 10**9+7
N, K = map(int, input().split())
if K % 2:
    print(0)
else:
    dp = [[[0]*(2*N**2) for _ in range(N+1)] for _ in range(N+1)]
    dp[0][0][0] = 1
    for i in range(N):
        for k in range(i+2):
            for S in range(-N**2+1, N**2):
                d = dp[i][k][S]
                if not d:
                    continue
                dp[i+1][k][S] = (dp[i+1][k][S]+(2*k+1)*d)%mod
                dp[i+1][k+1][S-2*(i+1)] = (dp[i+1][k+1][S-2*(i+1)]+d)%mod
                dp[i+1][k-1][S+2*(i+1)] = (dp[i+1][k-1][S+2*(i+1)]+k*k*d)%mod
    print(dp[N][0][K])