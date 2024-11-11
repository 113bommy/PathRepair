n, m = map(int, input().split())
s = list(map(int, input().split()))
t = list(map(int, input().split()))
mod = 1000000007
dp = [1] + [1] * m
for i in range(n):
    newdp = [1] + [0] * m
    for j in range(m):
        if s[i] == t[j]:
            newdp[j + 1] = (newdp[j] + dp[j + 1]) % mod
        else:
            newdp[j + 1] = (newdp[j] + dp[j + 1] - dp[j] + mod) % mod
    dp = newdp
print(dp[-1])