'''
template author-: Pyduper
'''
import sys

def input():
	return sys.stdin.readline().strip()

MAX = pow(10, 6)

n, c = map(int, input().split())

A = list(map(int, input().split()))
B = list(map(int, input().split()))

dp = [[MAX]*2 for _ in range(n)]
dp[0] = [0, c]

for i in range(n-1):
	dp[i+1][0] =  min(dp[i+1][0], dp[i][0]+A[i])
	dp[i+1][0] =  min(dp[i+1][0], dp[i][1]+A[i])
	dp[i+1][1] =  min(dp[i+1][1], dp[i][0]+B[i] + c)
	dp[i+1][1] =  min(dp[i+1][1], dp[i][1]+B[i])

for i in range(n):
	print(min(*dp[i]), end=" ")