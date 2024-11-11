n, b = map(int, input().split())
a = list(map(int, input().split()))

dp = [[0] * 100 for i in range(100)]
balance = 0
mx = 0
for i in range (len(a)-1):
    if a[i] % 2: balance += 1
    else: balance -= 1
    for j in range(b):
        dp[i+1][j] = max(dp[i+1][j], dp[i][j])
        if (balance == 0 and j + abs(a[i] - a[i+1]) < b):
            dp[i+1][j + abs(a[i] - a[i+1])] = max(dp[i+1][j + abs(a[i] - a[i+1])], dp[i][j] + 1)
            mx = max(mx, dp[i+1][j+abs(a[i] - a[i+1])])
print(mx)

