mod=998244353 

N=int(input())
alist=[]
all_num=1
for i in range(N):
  alist.append(int(input()))
  all_num *= 3
  all_num %= mod
  
asum=sum(alist)
#print(alist)
#print(all_num)

dp=[]
dp2=[]
for _ in range(N+1):
  dp.append([0]*(asum+1))
  dp2.append([0]*(asum+1))
  
dp[0][0]=1
dp2[0][0]=1
#print(dp)
for i in range(N):
  a=alist[i]
  for j in range(asum):
    dp[i+1][j] += 2*dp[i][j]
    dp[i+1][j] %= mod
    dp2[i+1][j] += dp2[i][j]
    dp2[i+1][j] %= mod
    if dp[i][j] > 0:
      dp[i+1][j+a] += dp[i][j]
      dp[i+1][j+a] %= mod
      dp2[i+1][j+a] += dp2[i][j]
      dp2[i+1][j+a] %= mod
    
#print(dp)
#print(dp2)

invalid_num = sum(dp[N][(asum+1)//2:])%mod 
#print(invalid_num)

if asum%2 == 0:
  print((all_num-3*invalid_num+3*dp2[N][asum//2])%mod)
else:
  print((all_num-3*invalid_num)%mod)