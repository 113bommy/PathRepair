MOD = 1000000007

N,K = map(int,input().split())
A = list(map(int,input().split()))

dp = [[0 for j in range(K+1)] for i in range(N+1)]
dp[0][0] = 1

for i in range(1,N+1):
    cum = [0 for j in range(K+2)]
    cum[0] = 0
    for j in range(1,K+2):
        cum[j] = cum[j-1]+dp[i-1][j-1]
        cum[j] %= MOD
    for j in range(K+1):
        dp[i][j] = cum[j+1]-cum[max(0,j-A[i-1])]
        dp[i][j] %= MOD

print(dp[N][K])