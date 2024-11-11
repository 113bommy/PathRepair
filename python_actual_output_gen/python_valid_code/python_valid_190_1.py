s = input()
t = input()
lenS = len(s)
lenT = len(t)

dp = [[0]*(lenT+1)for _ in range(lenS+1)]

for i in range(1,lenS+1):
  for j in range(1,lenT+1):
    if s[i]==t[j]:
      dp[i][j]=dp[i-1][j-1]+1
    else:
      dp[i][j]=max(dp[i-1][j],dp[i][j-1])
      
m = lenS
n = lenT
ans = ""
while m or n:
  if dp[m][n] == dp[m-1][n]:
    m -= 1
    continue
  elif dp[m][n] == dp[m][n-1]:
    n -= 1
    continue
  else:
    m -= 1
    n -= 1
    ans = "".join([s[m],ans])
    continue
print(ans)    