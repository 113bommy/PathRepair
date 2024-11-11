K = list(map(int, list(input())))
D = int(input())
N = len(K)
dp = [[[0]*D for _ in range(2)] for _ in range(N+1)]
mod = 10**9+7
dp[0][0][0] = 1

for i in range(N):
    for smaller in range(2):
        for j in range(D):
            for x in range(10 if smaller else K[i]+1):
                dp[i+1][smaller or int(x < K[i])][j] = (dp[i+1][smaller or int(x < K[i])][j] + dp[i][smaller][(j-x)%D]) % mod

print((dp[N][0][0]+dp[N][1][0]) % mod - 1)