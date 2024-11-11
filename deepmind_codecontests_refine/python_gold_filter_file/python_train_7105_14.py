# f = open('test.py')
# def input():
# 	return f.readline().replace('\n','')

# import heapq
# import bisect
# from collections import deque
# from collections import defaultdict
def read_list():
	return list(map(int,input().split(' ')))
def print_list(l):
	print(' '.join(map(str,l)))

n = int(input())
# for _ in range(N):
nums = read_list()
if n==3:
	print(sum(nums)-min(nums))
elif n==1:
	print(nums[0])
else:
	dp = [0] * n
	dp[0] = nums[0]
	dp[3] = nums[0] + nums[3]
	for i in range(2,n-1,2):
		dp[i] = dp[i-2]+nums[i]
	for i in range(5,n-1,2):
		dp[i] = min(dp[i-2],dp[i-3])+nums[i]
	res = min(dp[n-3],dp[n-2])

	dp = [0] * n
	dp[1] = nums[1]
	dp[4] = nums[1] + nums[4]
	for i in range(3,n,2):
		dp[i] = dp[i-2]+nums[i]
	for i in range(6,n,2):
		dp[i] = min(dp[i-2],dp[i-3])+nums[i]
	res = min(dp[n-1],dp[n-2],res)

	res = min(res,sum(nums[2::2]))
	print(sum(nums)-res)


