n,m=map(int,input().split(' '))
Mod=1000000007
spl=int(n**0.5)+1
f,k=[i for i in range(spl)]+[n//i for i in range(1,spl)][::-1],2*spl-1
dp=[0]+[1]*(k-1)
for i in range(m):
	dp2=[0]*k
	for j in range(1,k):
		dp2[j]=(dp2[j-1]+dp[k-j]*(f[j]-f[j-1]))%Mod
	dp=dp2
print(dp[k-1])