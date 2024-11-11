input_ = list(map(int,input().split()))
n, k ,d  = input_[0], input_[1], input_[2]

'''
def opt_tree(n,k,d):
	if d > n or n <= 0:
		return 0
	if n == 1 :
		return 1
	if d == n:
		return 1
	return  sum([opt_tree(n-i, k, (d-i)*(i>=d) + d*(i<d) ) for i in range(1,k+1)]) + (n<=k)
'''




dp = [['None' for i in range(d+1)] for j in range(n+1) ]

#Initialize
for j in range(d+1):
	#case 1
	dp[0][j] = 0

	for i in range(n+1):
		if j > i :
			dp[i][j] = 0
	#case 2
	if dp[1][j] == 'None':
		dp[1][j] = 1
	# case 3
	for i in range(min(d+1,n+1)):
		if dp[i][i] == 'None':
			dp[i][i] = 1

#main step
for n_temp in range(1,n+1):
	for d_temp in range(d+1):
		if dp[n_temp][d_temp] == 'None':
			dp[n_temp][d_temp] = sum([dp[n_temp -i][((d_temp-i)*(i>=d_temp) + d_temp*(i<d_temp))*(((d_temp-i)*(i>=d_temp) + d_temp*(i<d_temp))>=0)] for i in range(1,min([k+2,n_temp+1]))] ) + (n_temp <= k)



print(dp[n][d]%(10**9+7))
