from sys import stdin
input=lambda : stdin.readline()
from math import ceil,sqrt,gcd
n,h,l,r=map(int,input().split())
z=list(map(int,input().split()))
dp=[[0 for i in range(n+1)] for i in range(n+1)]
s=0
for i in range(n):
	s+=z[i]
	for j in range(i+1):
		if l<=(s-j)%h<=r:
			dp[i+1][j]=max(dp[i+1][j],dp[i][j]+1)
			if j!=n:
				dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]+1)
		else:
			dp[i+1][j]=max(dp[i+1][j],dp[i][j])
			if j!=n:
				dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j])
# print(dp)
print(max(dp[n]))