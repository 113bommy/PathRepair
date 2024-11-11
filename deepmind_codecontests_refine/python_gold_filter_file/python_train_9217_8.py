def solution(x, a, b): 
    n = len(a)
    dp = [[0] * 3 for i in range(n)]

    dp[0][0] = 1;
    dp[0][1] = 0;
    dp[0][2] = 0;

    if a[0] == 0: dp[0][1] = -1;
    if b[0] == 0: dp[0][2] = -1;

    for i in range(1, n): 
        dp[i][0] = dp[i-1][0] + 1
        dp[i][1] = dp[i-1][0]
        dp[i][2] = dp[i-1][0]

        if dp[i-1][1] != -1:
            dp[i][0] = min(dp[i][0], dp[i-1][1] + 1)
            dp[i][2] = min(dp[i][2], dp[i-1][1])

        if dp[i-1][2] != -1:
            dp[i][0] = min(dp[i][0], dp[i-1][2] + 1)
            dp[i][1] = min(dp[i][1], dp[i-1][2])

        if a[i] == 0: dp[i][1] = -1
        if b[i] == 0: dp[i][2] = -1

    min_days = dp[-1][0];
    if dp[-1][1] != -1: min_days = min(min_days, dp[-1][1])
    if dp[-1][2] != -1: min_days = min(min_days, dp[-1][2])

    return min_days * x

n = int(input())
c = list(map(int, input().split()))

a = [0] * n
b = [0] * n

for i in range(n): 
    if c[i] == 1: a[i] = 1;
    if c[i] == 2: b[i] = 1;
    if c[i] == 3:
        a[i] = 1;
        b[i] = 1;

print(solution(1, a, b))
