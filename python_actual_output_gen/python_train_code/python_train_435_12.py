N, K  = list(map(int,input().split()))
A = list(map(int,input().split()))

dp = [None for _ in range(K+1)]
dp[0] = 0
for k in range(1,K+1):
	for a in A:
		if k-a>=0:
			if dp[k-a]==0:
				dp[k]=1


if dp[K]==1:
	print('First')
else:
	print('Second')