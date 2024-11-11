from collections import defaultdict

MOD = 998244353
N,S = map(int,input().split())
A = map(int,input().split())

dp = [0]*(S+1)
dp[0] = 1
for a in A:
    ndp = [0]*(S+1)
    for total,cnt in enumerate(dp):
        ndp[total] += (dp[total]*2)%MOD
        if total+a <= S:
            ndp[total+a] += dp[total]
            ndp[total+a] %= MOD
    dp = ndp

print(dp[-1])