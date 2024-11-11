n, a, b, c = [int(x) for x in input().split()]

dp = [0] + [float('-inf')] * n

# for i in range(a, n+1):
# 	dp[i] = max(dp[i], dp[i-a]+1)

# # print(dp)


# for i in range(b, n+1):
# 	dp[i] = max(dp[i], dp[i-b]+1)


# # print(dp)
# for i in range(c, n+1):
# 	dp[i] = max(dp[i], dp[i-c]+1)


for i in range(1, n+1):
	for s in [a, b, c]:
		if i-s >= 0:
			dp[i] = max(dp[i], dp[i-s]+1)

print(dp[-1])


# print(dp)

print(dp[n])


#           _
#   	    _|
# 	  _|
#     _|
#   _|
# _|

