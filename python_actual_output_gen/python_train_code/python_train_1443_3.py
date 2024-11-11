n = int(input())
s = input()
dp = [0] * 4
a = list(map(int, input().split()))
for i in range(len(s)):
    if s[i] == "h":
        dp[0] += a[i]
    elif s[i] == "a":
        dp[1] = min(dp[0], dp[1] + a[i])
    elif s[i] == "r":
        dp[2] = min(dp[0], dp[2] + a[i])
    elif s[i] == "d":
        dp[3] = min(dp[0], dp[3] + a[i])

print(min(dp))