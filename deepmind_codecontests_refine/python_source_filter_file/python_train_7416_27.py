
mxn = 100000
dp = [0]*(mxn)
dp[0] = 2
for i in range(1,mxn):
	dp[i] = dp[i-1] + i + 2*(i+1)
#print(dp[:10])
#for i in range(1,11):
	#print(2*i*(i+1)//2 + (i-1)*i//2
	'''
for ii in range(int(input())):
	n = int(input())
	ans = 0
	for i in range(mxn-1,-1,-1):
		if dp[i] <= n:
			#print("check : ",dp[i],n)
			if n%dp[i] == 0:
				mul = n//dp[i]
				n-= dp[i]*mul
				ans+=mul
			else:
				n-=dp[i]
				ans+=1
	print(ans)
'''
import bisect
for ii in range(int(input())):
	n = int(input())
	count = 0
	while n >= 0:
		ind = bisect.bisect(dp,n)
		#print(ind, dp[ind-1])
		n -= dp[ind-1]
		count+=1
	print(count)
