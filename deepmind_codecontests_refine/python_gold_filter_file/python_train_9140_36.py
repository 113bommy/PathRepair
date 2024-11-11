N = int(input())
P = [float(i) for i in input().split()]

dp = [0.0] * (N + 1)
dp[0] = 1.0

for i, p in enumerate(P, 1):
    dp = [p * dp[j - 1] + (1 - p) * dp[j] for j in range(N + 1)]

print(sum(dp[-(-N // 2):]))