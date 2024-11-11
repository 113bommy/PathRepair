n,m=map(int,input().split())
a=list(map(int,input().split()))
dp=[0 for i in range(m)]
ans=0
for i in range(n):
	dp[i%m]+=a[i]
	ans+=dp[i%m]
	print (ans,end=" ")
