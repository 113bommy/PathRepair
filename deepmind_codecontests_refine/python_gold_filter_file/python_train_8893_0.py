from sys import stdin,stdout
input = stdin.readline
mp = lambda : map(int,input().split())
it = lambda: int(input())
n,k,d = mp()
mod = 10**9 +7
dp =[0]*(n+1)
dp1=[0]*(n+1)
dp[0] =1
dp1[0] =1
for i in range(1,n+1):
	for j in range(1,k+1):
		if i>=j:
			dp[i]+=dp[i-j]
		dp[i]%= mod
	for r in range(1,d):
		if i>=r:
			dp1[i]+=dp1[i-r]
		dp1[i]%= mod
print((dp[n]-dp1[n])%mod)