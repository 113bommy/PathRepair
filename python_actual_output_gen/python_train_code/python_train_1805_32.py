n = int(input())
s = [int(i) for i in input().split()]
s.reverse()
if n<=2:
	print(n)
else:
	dp = [0]*(n+1)
	dp[0]=1

	for i in range(1,n-1):
		if s[i-1]<=2*s[i]:
			dp[i]=dp[i-1]+1
		else:
			dp[i] = 1

	print(max(dp))