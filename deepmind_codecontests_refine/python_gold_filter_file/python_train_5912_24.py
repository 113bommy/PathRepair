n, k, c = map(int, input().split())
s = input()

s2 = s[::-1]

dp1 = [0] * (n + 2)
dp2 = [0] * (n + 2)

for (dp, ss) in zip([dp1, dp2], [s, s2]):
    for i in range(n):
        if ss[i] == 'x':
            dp[i+1] = dp[i]
        elif i <= c:
            dp[i+1] = min(1, dp[i] + 1)
        else:
            dp[i+1] = max(dp[i-c] + 1, dp[i])

dp2 = dp2[::-1]

for i in range(1, n+1):
    if s[i-1] == 'o' and dp1[i-1] + dp2[i+1] < k:
        print(i)
