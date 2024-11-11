n = int(input())
if(n == 1):
	print(1)
	exit(0)
a = [0 for x in range(n)]
h = [0 for x in range(n)]
for x in range(n):
	a[x], h[x] = map(int,input().split())

dp = [[0 for x in range(3)] for x in range(n)]
## 0 left 1 stay 2 right
L = 0
S = 1
R = 2
dp[0][L] = 1
dp[0][S] = 0
dp[0][R] = 1 if a[0] + h[0] < a[1] else 0
for x in range(1,n):
	## Stay
	dp[x][S] = max(dp[x-1][L],dp[x-1][S],dp[x-1][R])
	
	## Left
	if(a[x] - h[x] > a[x-1]):
		dp[x][L] = max(dp[x-1][L],dp[x-1][S]) ## S L
		if(a[x-1] + h[x-1] < a[x]):
			dp[x][L] = max(dp[x][L], dp[x-1][R]) ## R L
		dp[x][L] += 1
	else:
		dp[x][L] = max(dp[x-1][L],dp[x-1][S],dp[x-1][R])
	
	## Right
	if(x + 1 >= n or a[x] + h[x] < a[x+1]):
		dp[x][R] = max(dp[x-1][L],dp[x-1][S],dp[x-1][R]) + 1
	else:
		dp[x][R] = max(dp[x-1][L],dp[x-1][S],dp[x-1][R])
	
	## print(dp[x][L],dp[x][S],dp[x][R])

print(max(dp[n-1][L],dp[n-1][S],dp[n-1][R]))