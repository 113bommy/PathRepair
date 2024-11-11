N = input()
K = int(input())

dp = [[[0] * (K + 1) for _ in range(2)] for _ in range(len(N) + 1)]
dp[0][0][0] = 1

for i in range(len(N)):
    n = int(N[i])
    for j in range(2):
        for k in range(K + 1):
            for d in range((9 if j == 1 else n) + 1):
                if k + int(d != 0) <= K:
                    dp[i + 1][j | (d < n)][k + int(d != 0)] += dp[i][j][k]

cnt = len(N) - N.count("0")
print(dp[-1][-1][-1] + int(cnt <= K))
