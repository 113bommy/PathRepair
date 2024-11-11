n = int(input())
arr = list(map(int, input().split()))
maxx = 0
dp = [0 for i in range(n)]
dp[0] = 1
for i in range(n - 1):
    if arr[i] < arr[i + 1]:
        dp[i + 1] = dp[i] + 1
    else:
        dp[i + 1] = 1
    maxx = max(dp[i + 1], maxx)
print(maxx)