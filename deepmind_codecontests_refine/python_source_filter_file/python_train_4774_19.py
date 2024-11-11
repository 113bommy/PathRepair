MX = 401

N, Ma, Mb = map(int, input().split())
A = [0]*N
B = [0]*N
C = [0]*N
for i in range(N):
    a, b, c = map(int, input().split())
    A[i] = a
    B[i] = b
    C[i] = c
INF = 100
dp = [[[INF]*MX for i in range(MX)] for i in range(N+1)]
dp[0][0][0] = 0
for i in range(1, N+1):
    for j in range(0, MX):
        for k in range(0, MX):
            dp[i][j][k] = dp[i-1][j][k]
            if j < A[i-1] or k < B[i-1]: continue
            dp[i][j][k] = min(dp[i][j][k], dp[i-1][j-A[i-1]][k-B[i-1]]+C[i-1])
ans = INF
for i in range(1, MX):
    if Ma*i > MX-1 or Mb*i > MX-1: break
    ans = min(ans, dp[N][Ma*i][Mb*i])
if ans == INF:
    print(-1)
else:
    print(ans)
