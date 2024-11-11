N = input()
K = int(input())

def solve(N, K):
    l = len(N)
    dp = [[[0] * (10) for i in range(2)] for _ in range(l+1)]
    dp[0][0][0] = 1
    for i in range(l):
        D = int(N[i])
        for j in range(2):
            for k in range(K+1):
                for d in range(10):
                    if j == 0 and d > D: break
                    dp[i+1][j or (d < D)][k if d != 0 else k+1] += dp[i][j][k]
    
    return dp[l][0][K] + dp[l][1][K]

print(solve(N,K))

