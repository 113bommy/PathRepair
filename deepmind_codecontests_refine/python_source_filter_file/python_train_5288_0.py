n, k = map(int, input().split())
r, s, p = map(int, input().split())
d = {"r":p, "s":r, "p":s}
t = list(input())
dp = [0]*n
for i in range(n):
  if i>k and dp[i-k]==d[t[i]]:
    dp[i] = 0
    t[i] = "x"
  else:
    dp[i] = d[t[i]]
print(sum(dp))
