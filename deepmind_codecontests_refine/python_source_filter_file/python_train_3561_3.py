n = int(input())
a = list(map(int, input().split()))
dp = [0 for _ in range(2)]
pre = -1
for i in range(n):
    if a[i]%2 == 0:
        dp[0] += a[i]//2
        dp[1] += a[i] - a[i]//2
    else:
        dp[0] += a[i] - a[i]//2
        dp[1] += a[i]//2
print(min(dp[0], dp[1]))
