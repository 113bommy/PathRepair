t = int(input())
for _ in range(t):
    dp = [2]
    a = int(input())
    i = 1
    while dp[-1] <= a:
        dp.append(dp[i - 1] + i + 2 * (i + 1))
        i += 1
    ans = 0
    dp.reverse()
    for i in range(len(dp)):
        while a - dp[i] >= 0:
            a -= dp[i]
            ans += 1
        else:
            continue
    print(ans)
