n = int(input())
s = input()

dp = [0] * (len(s) + 1)
pn = [0] * (len(s) + 1)

pn[len(pn) - 1] = 1
for k in range(len(s) - 1, -1, -1):
    num = 0
    dp[k] = -1
    if (s[k] == '0'):
        dp[k] = pn[k + 1] * num + dp[k + 1];
        pn[k] = pn[k + 1] * n;
        continue;
        
    for i in range(k, len(s)):
        num = num * 10 + int(s[i])
        if (num > n): break;
        if (dp[k] == -1 or pn[i + 1] * num + dp[i + 1] < dp[k]):
            dp[k] = pn[i + 1] * num + dp[i + 1];
            pn[k] = pn[i + 1] * n;
print(dp[0]);
