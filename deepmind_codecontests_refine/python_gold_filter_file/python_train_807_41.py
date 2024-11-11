n = int(input())
a = list(map(int,input().split()))
b = sorted(a, reverse=True)
dp = [[0]*(n+1) for _ in range(n+1)]
ans = 0
def f(s,e):
  return abs(e-s)*a[s]
for i in range(n):
  d = a.index(b[i])
  for l in range(0,i+1):
    r = i-l
    dp[l+1][r] = max(dp[l+1][r], dp[l][r]+f(d,l))
    dp[l][r+1] = max(dp[l][r+1], dp[l][r]+f(d,n-r-1))
  a[d] = 0
for i in range(n+1):
  ans = max(ans, dp[i][n-i])
print(ans)