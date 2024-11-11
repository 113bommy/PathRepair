n,m=map(int,input().split())
a=set([int(input()) for i in range(m)])
mod=1000000007
dp=[1,1]
if 1 in a:
  dp[1]=0
for i in range(2,n+1):
  if i in a:
    dp.append(0)
  else:
    dp.append((dp[-1]+dp[-2])%mod)
print(dp[-1]%mod)
