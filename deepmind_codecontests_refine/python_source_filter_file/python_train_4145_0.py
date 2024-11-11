n,m = map(int,input().split())
s = input().rstrip()
mod = 10**9+7
if s.count("R") == 0 or s.count("B") == 0:
  dp = [[0 for i in range(2)] for j in range(n)]
  dp[0][0] = 1
  dp[0][1] = 1
  for i in range(1,n):
    dp[i][0] = (dp[i-1][0]+dp[i-1][1])%mod
    dp[i][1] = dp[i-1][0]
  print((dp[n-1][0]+dp[n-2][1])%mod)
  exit()
if n%2:
  print(0)
  exit()
x = s[0]
flg = 1
cnt = 0
ncnt = 0
for i in range(m):
  if s[i] == x:
    cnt += 1
  elif flg == 1:
    flg = 0
    ncnt = cnt
    cnt = 0
  else:
    if cnt%2:
      ncnt = min(ncnt,cnt)
    cnt = 0
if ncnt == 1:
  print(2)
  exit()
y = ncnt//2
dp = [[0 for i in range(2)] for j in range(n//2)]
dp[0][0] = 1
dp[0][1] = 1
for i in range(1,n//2):
  dp[i][0] = dp[i-1][0]+dp[i-1][1]
  if i<y:
    dp[i][1] = dp[i-1][0]+dp[i-1][1]
  elif i == y:
    dp[i][1] = sum([dp[j][0] for j in range(y)])
  else:
    dp[i][1] = dp[i-1][1]+dp[i-1][0]-dp[i-y-1][0]
  dp[i][0] %= mod
  dp[i][1] %= mod
ans = dp[-1][0]+dp[-1][1]
for j in range(1,y+1):
  if n//2-(y+j)-2 >= 0:
    ans = (ans-(dp[n//2-(y+j)-2][0])*(y+1-j))%mod
  elif n//2-(y+j) >= 0:
    ans -= y+1-j
print(2*ans%mod)