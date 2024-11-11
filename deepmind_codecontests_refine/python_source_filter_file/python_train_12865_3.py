from sys import stdin
input=lambda : stdin.readline().strip()
from math import ceil,sqrt,factorial,gcd
from collections import deque
n,m=map(int,input().split())
l=[list(map(int,input().split())) for i in range(n)]
dp=[[0 for i in range(m)] for i in range(n)]
k=int(input())
for j in range(m):
	dp[n-1][j]=n-1
	a=n-1
	for i in range(n-2,-1,-1):
		if l[i][j]>l[i+1][j]:
			a=i
		dp[i][j]=a
z=[0 for i in range(n)]
for i in range(n):
	# print(*dp[i])
	for j in range(m):
		z[i]=max(z[i],dp[i][j])
# print(z)
for i in range(k):
	a,b=map(int,input().split())
	a-=1
	b-=1
	if z[a]>=b:
		print("YES")
	else:
		print("NO")