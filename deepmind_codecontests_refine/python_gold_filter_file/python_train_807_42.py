N = int(input())
A = list(map(int, input().split()))

infants = [[i, A[i]] for i in range(N)]
infants.sort(key=lambda x:x[1], reverse=True)

dp = [[0 for _ in range(N+1)] for _ in range(N+1)]

for x in range(N):
    for y in range(N-x):
        pos, infant = infants[x+y]
        dp[x][y+1] = max(dp[x][y+1], dp[x][y]+infant*abs(N-1-y-pos))
        dp[x+1][y] = max(dp[x+1][y], dp[x][y]+infant*abs(pos-x))

ans = 0
for i in range(N):
    ans = max(ans, dp[i][N-i])
print(ans)