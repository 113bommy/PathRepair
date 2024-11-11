N, K = map(int, input().split())
H = [0] + list(map(int, input().split()))

DP = [0] * (N+1)

for i in range(2, N+1):
  k = max(i-K, 0)
  DP[i] = min(dp + abs(h - H[i]) for dp, h in zip(DP[k:i], H[k:i]))
print(DP[N])
