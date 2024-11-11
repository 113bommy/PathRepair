n,a,*x=map(int,open(0).read().split());dp={0:1}
for i in x:
	for k,v in dp.items():
		dp[i+k-a]=dp.get(i+k-a,0)+v
print(dp[0]-1)