
N = int(input())
A = list(map(int, input().split()))
C = [0, A.count(1), A.count(2), A.count(3)]
dp = [[[0.0] * (N+1) for _ in range(N+1)] for _ in range(N+1)]

for k in range(C[3]+1):
    for j in range(C[3]+C[2]+1-k):
        for i in range(N+1-j-k):
            if i + j + k == 0:
                continue
            res = N
            if i > 0:
                res += i * dp[i-1][j][k]
            if j > 0:
                res += j * dp[i+1][j-1][k]
            if k > 0:
                res += k * dp[i][j+1][k-1]
            dp[i][j][k] = res / (i + j + k)
 
print(dp[C[1]][C[2]][C[3]])