n = int(input())
a = list(map(int, input().split()))

babies = [(a, i) for i, a in enumerate(a)]
babies.sort(reverse=True)

dp = [[0 for _ in range(n)] for _ in range(n)]
ans = 0
for l in range(n):
  for r in range(n):
    if l+r == n:
      ans = max(ans, dp[l][r])
      break
    activeness, ind = babies[l+r]
    dp[l+1][r] = max(dp[l+1][r], dp[l][r] + activeness * abs(ind - l))
    dp[l][r+1] = max(dp[l][r+1], dp[l][r] + activeness * abs(ind - (n - 1 - r)))
print(ans)