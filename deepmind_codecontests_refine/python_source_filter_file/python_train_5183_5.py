N = int(input())
A = list(map(int, input().split()))

dp = [0] * (N + 1)
dp[2] = max(A[0], A[1])
s = 0
for i, a in enumerate(A, 1):
  if i <= 2:
    continue
  if i%2: # 奇数
    dp[i] = max(dp[i-1], a+dp[i-2])
    s += a
  else: # 偶数
    dp[i] = max(a+dp[i-2], s)

print(dp[-1])