K = input()
D = int(input())
L = len(K)
mod = 10 ** 9 + 7

dp = [[[0] * 2 for _ in range(D)] for _ in range(L+1)]
dp[0][0][0] = 1

for i in range(L):
    nd = int(K[i])
    for j in range(D):
        for k in range(2):
            #lim = 9 if k == 1 else nd
            for d in range(10):
                nk = k
                if k == 0:
                    if d > nd:
                        continue
                    if d < nd:
                        nk = 1
                dp[i+1][(j+d) % D][nk] += dp[i][j][k]
                dp[i+1][(j+d) % D][nk] %= mod

ans = (dp[L][0][0] + dp[L][0][1] - 1) % mod

#for i in range(L+1):
#    print(dp[i])
print(ans)
