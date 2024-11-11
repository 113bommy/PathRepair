S = input()
 
dp = [[0]*13 for j in range(len(S)+1)]
mod = 10**9+7
 
dp[0][0] = 1
k = 1
L0 = list(range(10))

for s in S:
  if ('?' == s):
    L = L0
  else:
    L = [int(s)]
 
  for l in L:
    for i in range(13):
      tmp = (i * 10) + l
      m = tmp % 13
      dp[k][m] = ((dp[k][m][0] + dp[k-1][i][0]) % mod)
  k += 1
print(dp[k-1][5])
