N, K = map(int, input().split())
H = list(map(int, input().split()))
dp = [0] * N
for i in range(1, N):
    dp[i] = min([dp[j] + abs(H[i] - H[j]) for j in range(max(i-K, 0), i)])
print(dp[-1])