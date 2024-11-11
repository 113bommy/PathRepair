s = input()
q = s.count("?")
ans = [0] * 13
ans[0] = 1

for v in s:
    dp = [0] * 13
    for j in range(13):
        dp[(j * 10) % 13] = ans[j] % 1000000007
    dp += dp
    for j in range(13):
        if v == '?':
            ans[j] = sum(dp[j+4:j+14])
        else:
            ans[j] = dp[j - int(v)]

print(ans[5] % 1000000007)
