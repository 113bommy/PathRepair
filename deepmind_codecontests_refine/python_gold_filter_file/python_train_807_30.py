N = int(input())
A = list(map(int,input().split()))
B = sorted([(a,i) for i,a in enumerate(A)])

dp = [[0]*(N+1) for _ in range(N+1)]
for i in range(N):
    a,j = B.pop()
    for k in range(i+1):
        dp[k][i-k+1] = max(dp[k][i-k+1], dp[k][i-k] + a * abs(j-(N-1-(i-k))))
        dp[k+1][i-k] = max(dp[k+1][i-k], dp[k][i-k] + a * abs(j-k))

print(max(dp[i][N-i] for i in range(N+1)))