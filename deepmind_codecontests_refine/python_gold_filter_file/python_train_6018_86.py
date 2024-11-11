MOD = 10 ** 9 + 7
S = input()

dp = [0] * 13
dp[0] = 1

for s in S:
  prev = [x for x in dp]
  dp = [0] * 13
  if s == '?':
    add = range(10)
  else:
    add = [int(s)]
  for i in range(13):
    for x in add:
      dp[(10*i+x)%13] += prev[i]
  dp = [x % MOD for x in dp]
  
print(dp[5])
