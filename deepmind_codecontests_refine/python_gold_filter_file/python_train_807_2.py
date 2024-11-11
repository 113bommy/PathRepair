#  from pprint import pprint
n = int(input())
a = map(int, input().split())
a = sorted(((ax, x) for x, ax in enumerate(a)), reverse=True)
dp = [[-1] * (n+1) for _ in range(n+1)]
dp[0][0] = 0
for i, (ax, x) in enumerate(a):
    for j in range(i+1):
        dp[j+1][i-j] = max(dp[j+1][i-j], dp[j][i-j] + ax*abs(x-j))
        dp[j][i-j+1] = max(dp[j][i-j+1], dp[j][i-j] + ax*abs(n-1-x-i+j))
# pprint(dp)
print(max(dp[i][n-i] for i in range(n+1)))
