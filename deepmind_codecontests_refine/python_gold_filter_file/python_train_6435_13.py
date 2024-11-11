k = input()
d = int(input())
mod = 10**9+7
if d == 1:
    print(int(k)%mod)
    exit()
dp = [[[0]*2 for i in range(d)] for j in range(len(k))]
## dp[][][0] k 以下確定 [1] 未定

s = int(k[0])
dp[0][s%d][1] = 1
for i in range(s):
    dp[0][i%d][0] = 1

for i in range(1,len(k)):
    s = int(k[i])
    for j in range(10):
        for m in range(d):
            if s == j:
                dp[i][(m+j)%d][1] += dp[i-1][m][1]
                dp[i][(m+j)%d][1] %= mod
            elif s > j:
                dp[i][(m+j)%d][0] += dp[i-1][m][1]
                dp[i][(m+j)%d][0] %= mod
            dp[i][(m+j)%d][0] += dp[i-1][m][0]
            dp[i][(m+j)%d][0] %= mod
ans = sum(dp[-1][0])

print((ans-1)%mod)