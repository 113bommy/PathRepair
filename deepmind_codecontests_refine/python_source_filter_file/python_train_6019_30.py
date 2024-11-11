n = int(input())
z = []
pre = 0
for _ in range(n):
    i = int(input())
    if i != pre:
        z.append(i)
    pre = i
n = len(z)
dp = [1] * (n+1)
dpp = [0] * 2 * 10 ** 5
for i in range(n):
    dp[i+1] = dp[i] + dpp[z[i]-1]
    dpp[z[i]-1] += dp[i+1]
    dp[i+1] %= 10 ** 9 + 7
print(dp[n])