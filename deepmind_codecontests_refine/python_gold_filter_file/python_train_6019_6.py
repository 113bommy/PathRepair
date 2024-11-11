n=int(input())
c=[int(input()) for _ in [0]*n]
l=[-1]*200001
dp=[1]*n
l[c[0]]=0
mod=10**+9+7
for i in range(1,n):
	ci=c[i]
	if l[ci] not in [-1,i-1]:
		dp[i]=(dp[i-1]+dp[l[ci]])%mod
	else:
		dp[i]=dp[i-1]
	l[ci]=i
print(dp[n-1])