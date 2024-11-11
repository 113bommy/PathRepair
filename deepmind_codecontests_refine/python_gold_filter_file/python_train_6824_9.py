from sys import stdin, stdout
INF = float('inf')
n = int(stdin.readline())
prices = list(map(int, stdin.readline().split()))
strings = []
for i in range(n):
    strings.append(stdin.readline().strip())
dp = [[INF, INF, INF, INF] for i in range(n)]
for i in range(n - 1):
    if not i:
        if strings[i] <= strings[i + 1]:
            dp[i][0] = 0
        if strings[i][::-1] <= strings[i + 1]:
            dp[i][1] = prices[i]
        if strings[i] <= strings[i + 1][::-1]:
            dp[i][2] = prices[i + 1]
        if strings[i][::-1] <= strings[i + 1][::-1]:
            dp[i][3] = prices[i] + prices[i + 1]
    else:
        if strings[i] <= strings[i + 1]:
            dp[i][0] = min(dp[i - 1][:2])
        if strings[i][::-1] <= strings[i + 1]:
            dp[i][1] = min(dp[i - 1][2:])
        if strings[i] <= strings[i + 1][::-1]:
            dp[i][2] = min(dp[i - 1][:2]) + prices[i + 1]
        if strings[i][::-1] <= strings[i + 1][::-1]:
            dp[i][3] = min(dp[i - 1][2:]) + prices[i + 1]

if min(dp[n - 2]) >= INF:
    stdout.write('-1')
else:
    stdout.write(str(min(dp[n - 2])))