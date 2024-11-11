h,n = map(int,input().split())
dp = [1e8] * (h+1)
dp[0] = 0
for i in range(n):
    a, b = map(int, input().split())
    for j in range(h):
        nj = min(j+a, h)
        dp[nj] = min(dp[nj], dp[j]+b)
print(dp[h])
