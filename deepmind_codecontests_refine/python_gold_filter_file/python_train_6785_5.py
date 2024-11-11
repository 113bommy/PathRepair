n=int(input())
v=list(map(int,input().split()))
a=[]
for _v in v:
	if _v:
		a.append(_v)
v=a
n=len(a)
if n>128:
	print(3)
	exit(0)
ans=1e10
dis=[[1e10 for _ in range(n)] for __ in range(n)]
dp=[[1e10 for _ in range(n)] for __ in range(n)]
for i in range(n):
	for j in range(n):
		if i!=j and v[i]&v[j]:
			dp[i][j]=dis[i][j]=1
for k in range(n):
	for i in range(k):
		for j in range(i+1,k):
			ans=min(ans,dp[i][j]+dis[i][k]+dis[k][j])
	for i in range(n):
		for j in range(n):
			dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j])
print([ans,-1][ans==1e10])
