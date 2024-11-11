n=int(input())
dp=[0]*(n+1)
dp[0]=1
pbl=list(map(float,input().split()))
for i in range(n):
	for j in range(i+1,-1,-1):
		dp[j]=dp[j-1]*pbl[i]+dp[j]*(1-pbl[i])
	# print(dp)
ans=0
for i in range((n+1)//2,n+1):
	ans+=dp[i]
print(ans)