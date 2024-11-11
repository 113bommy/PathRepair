n,m = map(int,input().split())
dp = [0]+[10**8+10]*(2**n-1)
for i in range(m):
  a,b = map(int,input().split())
  s = sum([2**(x-1) for x in list(map(int,input().split()))])
  for j in range(2**n):
    dp[j|s] = min(dp[j|s],dp[j]+a)
if dp[-1] <= 10**8:
  print(dp[-1])
else:
  print(-1)

