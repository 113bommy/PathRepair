s1=input()
s2=input()
dp=[0]*(len(s1)+1)
dp[0]=[0]*(len(s2)+1)
for i in range(1,len(s1)+1):
	dp[i]=[0]*(len(s2)+1)
	for j in range(1,len(s2)+1):
		if s1[i-1]==s2[j-1]:
			dp[i][j]=dp[i-1][j-1]+1
		else:
			dp[i][j]=max(dp[i-1][j],dp[i][j-1])
for i in range(len(s1)+1):
	print(dp[i])
s=""
i,j=len(s1),len(s2)
while(i>0 and j>0):
	if s1[i-1]==s2[j-1]:
		s+=s1[i-1]
		i-=1
		j-=1
	elif dp[i][j-1]>dp[i-1][j]:
		j-=1
	else:
		i-=1
print(s[::-1])