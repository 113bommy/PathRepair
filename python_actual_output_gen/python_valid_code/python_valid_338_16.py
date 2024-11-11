n=int(input())
dp=[]
for i in range(n):
  l=list(map(int,input().split()))
  dp.append(l)
for i in range(1,n):
  for j in range(3):
  	dp[i][(j%3)]+=max(dp[i][(j+1)%3],dp[i][(j+2)%3]) 
print(max(dp[n-1]))
  