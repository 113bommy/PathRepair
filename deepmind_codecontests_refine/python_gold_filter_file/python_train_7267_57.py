N = int(input())
A = list(map(float, input().split()))
def solve():
    dp = [[[0]*(N+1-i-j) for j in range(N+1-i)] for i in range(N+1)]
    dp[N][0][0] = 0
    for i in range(N-1,-1,-1):
        for j in range(N-i,-1,-1):
            for k in range(N-i-j,-1,-1):
                dp[i][j][k] = 1/(1-i/N)
                if j != 0:
                    dp[i][j][k] += dp[i+1][j-1][k]*(j/(N-i))
                if k != 0:
                    dp[i][j][k] += dp[i][j+1][k-1]*(k/(N-i))
                if i+j+k != N:
                    dp[i][j][k] += dp[i][j][k+1]*(1-(j+k)/(N-i))
    c = {}
    for i in range(1,3):
        c[i] = A.count(i)
    ans = dp[0][c[1]][c[2]]
    # print(*dp,sep='\n')
    return ans
print(solve())