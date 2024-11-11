mod=10**9+7
s=input()
s=s[::-1]
dp=[[0]*13 for _ in range(len(s)+1)]
dp[0][0]=1
for i in range(len(s)):
	p=pow(10,i,13)
	if s[i]=="?":	
		for k in range(13):
			for j in range(10):
				dp[i+1][(k+p*j)%13]+=dp[i][k]
				dp[i+1][(k+p*j)%13]%=mod
	else:
		for k in range(13):
			dp[i+1][(k+p*int(s[i]))%13]+=dp[i][k]
			dp[i+1][(k+p*int(s[i]))%13]%=mod
print(dp[-1][5])
