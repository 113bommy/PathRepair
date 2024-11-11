n = int(input())
*A, = map(int, input().split())
a, b, c = A.count(1), A.count(2), A.count(3)
DP = [[[0 for k in range(n+1)] for j in range(n+1)] for i in range(n+1)]
for k in range(c+1):
    for j in range(b+c-k+1):
        for i in range(n-j-k+1):
            if i+j+k == 0:
                continue
            tmp = n
            if i > 0:
                tmp += DP[i-1][j][k]*i
            if j > 0:
                tmp += DP[i+1][j-1][k]*j
            if k > 0:
                tmp += DP[i][j+1][k-1]*k
            DP[i][j][k] = tmp/(i+j+k)
print(DP[a][b][c])
