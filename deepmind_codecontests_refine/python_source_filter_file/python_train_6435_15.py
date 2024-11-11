k = input()
D = int(input())
mod = 10 ** 9 + 7
keta = len(k)
dp = [[[0] * (2) for _ in range(D)] for _ in range(keta + 1)]
# dp[keta][D][smaler]
dp[0][0][0] = 1
for i in range(keta):
    num = int(k[i])
    for j in range(D):
        for smaller in range(2):
            for d in range(10):
                ni = i + 1
                nsmaller = smaller
                nj = (j + d) % D
                if smaller == 0:
                    if d < num:
                        nsmaller = 1
                    if d > num:
                        continue
                dp[ni][nj][nsmaller] += dp[i][j][smaller]
                dp[ni][nj][nsmaller] %= mod
print(dp[keta][0][1] + dp[keta][0][0] - 1)
