import sys
input = sys.stdin.readline

def int_array():
	return list(map(int, input().strip().split()))

def float_array():
	return list(map(float, input().strip().split()))

def str_array():
	return input().strip().split()
from collections import Counter
import math
import bisect
from collections import deque
n,m,lesson=int_array()
dp=[[1000 for i in range(lesson+2)]for j in range(n+1)]
days=[[] for i in range(n)]
for i in range(n):
	s=input()
	for  j in range(m):
		if s[j]=="1":
			days[i].append(j+1)

m=[[1000 for i in range(lesson+2)]for j in range(n+1)]
for i in range(n):
	for j in range(lesson+1):
		if j<=len(days[i]):
			if j==len(days[i]):
				m[i][j]=0
				continue
			else:
				for k  in range(0,j+1):
					var=days[i][0+k]
					var1=days[i][-1*max(1,1+(j-k))]
					m[i][j]=min(m[i][j],var1-var+1)



for i in range(lesson+1):
	dp[0][i]=m[0][i]
for i in range(1,n):
	for j in range(lesson+1):
		for k in range(j+1):

			dp[i][j]=min(dp[i][j],dp[i-1][j-k]+m[i][k])
			#dp[i][j] = min(dp[i][j], dp[i - 1][k]+m[i][j-k])

print(min(dp[n-1]))

