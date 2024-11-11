from sys import stdin
input = stdin.readline
n, v = map(int, input().split())
dp = [0 for i in range(n)]
if v > n:
	v = n-1
curL = v
dp[0] = v
for i in range(1, n):
	curL -= 1
	if curL < (n-(i+1)):
		c = v - curL
		curL = v
		dp[i] = (c * (i+1)) + dp[i-1]
	else:
		dp[i] = dp[i-1]
print(dp[n-1])