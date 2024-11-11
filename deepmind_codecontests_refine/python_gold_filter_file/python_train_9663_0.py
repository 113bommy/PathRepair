s = input()

m = 1000000007
dp = [0] * 4
dp[0] = 1

for c in s:
  if c=='A':
    dp[1] += dp[0]
  elif c=='B':
    dp[2] += dp[1]
  elif c=='C':
    dp[3] += dp[2]
  elif c=='?':
    dp = [(dp[0]*3)%m, (dp[0]+dp[1]*3)%m, (dp[1]+dp[2]*3)%m, (dp[2]+dp[3]*3)%m]

print(dp[3]%m)