S = input()
MOD = 10 ** 9 + 7

dp = [0] * 13
dp[0] = 1

for s in S:
    prev = dp
    dp = [0] * 13
    if s == '?':
        add = range(10)
    else:
        add = [int(s)]
    for i in range(13):
        for a in add:
            dp[(10*i+a)%13] += prev[i]
    dp = [x%MOD for x in dp]
print(dp[5])