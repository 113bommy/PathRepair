s = input()
n = len(s)
cA = ord('a')
P = {0: -1}
cur = 0

dp = [10**18]*(n+1)
dp[-1] = 0

for i in range(n):
    c = ord(s[i]) - cA
    dp[i] = dp[i-1] + 1
    cur ^= 1 << c
    # even
    if cur in P:
        dp[i] = min(dp[i], P[cur] + 1)
    # odd
    for k in range(26):
        need = cur ^ (1 << k)
        if need in P:
            dp[i] = min(dp[i], P[need] + 1)
    P[cur] = min(P.get(cur, 10**18), dp[i])
print(dp[n-1])