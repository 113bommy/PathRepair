md = 10 ** 9 + 7
n = int(input())
s = input()
dp = [1] * n
for i in range(n - 1):
    if s[i] == "<":
        s = dp[0]
        for dpi in range(1, n - i - 1):
            dp[dpi] = s = (dp[dpi] + s) % md
        dp = dp[:-1]
    else:
        s = dp[-1]
        for dpi in range(n - i - 2, 0, -1):
            dp[dpi] = s = (dp[dpi] + s) % md
        dp = dp[1:]
print(dp[0])
