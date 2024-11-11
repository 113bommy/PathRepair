N = int(input())
A = list(map(int,input().split()))

A = [[A[i],i] for i in range(N)]
A.sort()

dp = [[0]*(N+1) for i in range(N+1)]

ans = 0
for i in range(N+1):
    for j in range(N+1):
        if i+j>N:
            continue
        if i+j==0:
            continue
        a,k = A[-i-j]
        if i==0:
            dp[i][j] = dp[i][j-1]+a*(N-j-k)
        elif j==0:
            dp[i][j] = dp[i-1][j]+a*(k-i+1)
        else:
            dp[i][j] = max(dp[i-1][j]+a*(k-i+1),dp[i][j-1]+a*(N-j-k))
        ans = max(ans,dp[i][j])
print(ans)