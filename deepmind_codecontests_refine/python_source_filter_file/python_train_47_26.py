#                                               |
#   _` |  __ \    _` |   __|   _ \   __ \    _` |   _` |
#  (   |  |   |  (   |  (     (   |  |   |  (   |  (   |
# \__,_| _|  _| \__,_| \___| \___/  _|  _| \__,_| \__,_|

import sys
import math
import operator as op
from functools import reduce

def read_line():
    return sys.stdin.readline()[:-1]
 
def read_int():
    return int(sys.stdin.readline())
    
def read_int_line():
    return [int(v) for v in sys.stdin.readline().split()]

def read_float_line():
    return [float(v) for v in sys.stdin.readline().split()]

def ncr(n, r):
    r = min(r, n-r)
    numer = reduce(op.mul, range(n, n-r, -1), 1)
    denom = reduce(op.mul, range(1, r+1), 1)
    return numer / denom

# t = read_int()
t = 1
for i in range(t):
	n = read_int()
	l = []
	for i in range(n):
		x,h = read_int_line()
		l.append([x,h])

	dp = [[0,0] for i in range(n)]

	dp[0][0] = 1

	if n==1:
		print(1)
	else:
		if l[0][0]+l[0][1]<=l[1][0]:
			dp[0][1] = 1

		for i in range(1,n):
			if l[i][0]-l[i][1]>=l[i-1][0]:
				dp[i][0] = 1+dp[i-1][0]
			else:
				dp[i][0] = dp[i-1][0]

			if l[i][0]-l[i][1]>=l[i-1][0]+l[i-1][1]:
				dp[i][0] = max(dp[i][0],1+dp[i-1][1])
			else:
				dp[i][0] = max(dp[i][0],dp[i-1][1])

			v = max(dp[i-1][0],dp[i-1][1])

			if i!=n-1 and l[i][0]+l[i][1]<l[i+1][0]:
				dp[i][1] = 1+v
			elif i==1:
				dp[i][1] = 1+v
			else:
				dp[i][1] = v

		m = -1
		for i in range(n):
			v = max(dp[i-1][0],dp[i-1][1])
			m = max(m,v)
		ans = m
		print(ans)

