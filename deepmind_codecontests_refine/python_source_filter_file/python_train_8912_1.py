dp = {}
input()
sum = 0
ans = 0
dp[0] = 0
for i, c in enumerate(input()):
    if c == "0":
        sum += 1
    else:
        sum -= 1
    if sum in dp:
        ans = max(ans, i - dp[sum])
    else:
        dp[sum] = i

print(ans)