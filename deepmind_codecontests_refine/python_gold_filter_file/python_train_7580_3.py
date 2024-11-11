N = int(input())
MB = {}; MW = {}
for i in range(2*N):
    c, a = input().split()
    c = "BW".index(c); a = int(a)
    if c:
        MW[a-1] = i
    else:
        MB[a-1] = i

P = [[0]*(N+1) for i in range(N+1)]
Q = [[0]*(N+1) for i in range(N+1)]

for p in range(N):
    cnt = MW[p] - sum(MW[p0] < MW[p] for p0 in range(p))

    P[p][0] = cnt
    for q in range(N):
        if MB[q] < MW[p]:
            cnt -= 1
        P[p][q+1] = cnt

for q in range(N):
    cnt = MB[q] - sum(MB[q0] < MB[q] for q0 in range(q))

    Q[q][0] = cnt
    for p in range(N):
        if MW[p] < MB[q]:
            cnt -= 1
        Q[q][p+1] = cnt

dp = [[10**9]*(N+1) for i in range(N+1)]
dp[0][0] = 0
for i in range(N):
    dp[i+1][0] = dp[i][0] + P[i][0]
for i in range(N):
    dp[0][i+1] = dp[0][i] + Q[i][0]
for i in range(N):
    for j in range(N):
        dp[i+1][j+1] = min(dp[i][j+1] + P[i][j+1], dp[i+1][j] + Q[j][i+1])
print(dp[N][N])