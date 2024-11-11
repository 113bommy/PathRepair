#45 ABC135D 桁DP
s=input()
n=len(s)
dp=[[0 for _ in range(13)] for _ in range(n+1)]
dp[0][0]=1
for i in range(n):
	if s[i]=="?":
		c=-1
	else:
		c=int(s[i])
	for j in range(10):
		if c!=-1 and c!=j:
			continue
		for ki in range(13):
			dp[i+1][(ki*10+j)%13]+=dp[i][ki]
	#for j in range(13):
		#dp[i+1][j]%=(10**9+7)
print(dp[n][5]%(10**9+7))