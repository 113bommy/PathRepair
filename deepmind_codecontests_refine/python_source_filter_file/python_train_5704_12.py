h, w = map(int, input().split())
a = lambda x: 1 if x=="#" else 0
S = [list(map(a, list(input()))) for _ in range(h)]
inf = 10*3
dp = [[inf]*w for _ in range(h)]
dp[0][0] = S[0][0]
for i in range(1, w):
    dp[0][i] = dp[0][i-1] + S[0][i]*(S[0][i]!=S[0][i-1])
for i in range(1, h):
    dp[i][0] = dp[i-1][0] + S[i][0]*(S[i][0]!=S[i-1][0])
for i in range(1, h):
    for j in range(1, w):
        dp[i][j] = min(dp[i-1][j]+S[i][j]*(S[i-1][j]==S[i][j]), dp[i][j-1]+S[i][j]*(S[i][j]!=S[i][j-1]))
print(dp[-1][-1])