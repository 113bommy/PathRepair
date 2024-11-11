n=int(input())
a=list(map(int,input().split()))
l=[abs(a[i+1]-a[i]) for i in range(n-1)]
dp=[[0,0] for i in range(n-1)]
dp[0][0]=l[0]
ans=0
for i in range(1,n-1):
	dp[i]=[max(dp[i-1][1]+l[i],l[i]),max(dp[i-1][0]-l[i],-l[i])]
	ans=max(ans,max(dp[i]))
print(ans)