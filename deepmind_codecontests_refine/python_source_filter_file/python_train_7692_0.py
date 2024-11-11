def differ(i,ss):
  tos = ["W","B","R"]
  count = 0
  for j in ss:
    if (j != tos[i]):
      count += 1
  return count
[n,m] = list(map(int,input().split()))
ls = []
for i in range(n):
  ls.append(input())
dp = [[0 for i in range(50)] for i in range(3)]
dp[0][0] = differ(0,ls[0])
for i in range(3):
  for j in range(n):
    if j == 0:
      if i == 0:
        dp[i][j] = differ(0,ls[0])
      else:
        dp[i][j] = 100
    if i == 0:
      dp[i][j] = dp[i][j-1] + differ(i,ls[j])
    else:
      dp[i][j] = min(dp[i-1][j-1] + differ(i,ls[j]),dp[i][j-1] + differ(i,ls[j]))
print(dp[2][n-1])