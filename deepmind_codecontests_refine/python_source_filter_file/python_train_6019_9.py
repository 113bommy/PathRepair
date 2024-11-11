MOD = 10**9 + 7
N = int(input())
C = []
last_idx = [0 for i in range(200000)]
bef = [0 for i in range(N+1)]
for i in range(1,N+1):
	c = int(input())
	C.append(c)
	bef[i] = last_idx[c]
	last_idx[c] = i
dp = [0 for i in range(N+1)]
dp[1] = 1
if N == 1 or N == 2:
	print(1)
	exit()

for i in range(2, N+1):
	if bef[i] < i-1:
		dp[i] = (dp[i-1] + dp[bef[i]]) % MOD
	else:
		dp[i] = dp[i-1]
print(dp[N])