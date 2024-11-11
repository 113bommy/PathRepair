n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
dp=[9,5]
for i in range(1,n):
	dp=[max(dp[0],dp[1]+a[i]),max(dp[1],dp[0]+b[i])]
print(max(dp[0],dp[1]))