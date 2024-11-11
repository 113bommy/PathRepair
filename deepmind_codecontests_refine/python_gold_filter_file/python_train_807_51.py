N = int(input())
S = list(map(int, input().split()))

data = [0]*N
for i, item in enumerate(S):
    data[i] = [item, i]
data.sort(reverse=True)

dp = [[0]*(N+1) for _ in range(N+1)]
# dp[i][j] i+j-1番目までの幼児がi人0から、j人N-1から並んだ時の最大値

for i in range(N):
    for j in range(N):
        if i+j >= N:
            break
        dp[i+1][j] = max(dp[i+1][j], dp[i][j]+data[i+j][0]*(data[i+j][1]-(i)))
        dp[i][j+1] = max(dp[i][j+1], dp[i][j]+data[i+j][0]*((N-1-j)-data[i+j][1]))

ans = 0
for i in range(N+1):
    ans = max(ans, dp[i][N-i])

print(ans)