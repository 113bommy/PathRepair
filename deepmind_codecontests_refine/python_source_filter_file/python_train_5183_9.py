n = int(input())
a = list(map(int, input().split()))
INF = 1001001001001001
c = n//2
dp = [[-INF]*3 for _ in range(c+1)]
dp[0][0] = 0
for i in range(c+1):
    for j in range(3):
        for k in range(3):
            if i+1<=c and j+k<3 and 2*i+j+k<n:
                dp[i+1][j+k] = max(dp[i+1][j+k], dp[i][j]+a[2*i+j+k])

ans = 0

for i in range(3):
    ans = max(ans,dp[c][i])

print(ans)