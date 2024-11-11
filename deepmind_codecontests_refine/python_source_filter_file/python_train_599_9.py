n,s,*a=map(int,open(0).read().split())
ans=0
mod=998244353
dp=[0]*(s+1)
for i in range(n):
	dp[0]+=1
	if a[i]>s:
		continue
	ans+=dp[s-a[i]]*(n-i)
	ans%=mod
	for j in range(s,a[i]-1,-1):
		dp[j]+=dp[j-a[i]]
		dp[j]%=mod
print(ans)