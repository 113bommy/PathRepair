K = int(input())
D = int(input())
n = len(str(K))

mod = 10**9+7

s = str(K)

dp = [[[0, 0] for _ in range(D)] for _ in range(n+1)]
dp[0][0][0] = 1

for i in range(n):
    for j in range(D):
        for k in range(2):
            nd = int(s[i])
            for d in range(10):
                ni = i+1
                nj = (j+d)%D
                nk = k
                if k == 0:
                    if d > nd:
                        continue
                    elif d < nd:
                        nk = 1
                    else:
                        pass
                dp[ni][nj][nk] += dp[i][j][k]%mod
print((dp[n][0][0]+dp[n][0][1]-1)%mod)