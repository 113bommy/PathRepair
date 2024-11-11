import sys
input=sys.stdin.readline
n,m,q=map(int,input().split())
num=[[0]*(n+1) for _ in range(n+1)]
for i in range(m):
	l,r=map(int,input().split())
	num[l][r]+=1
for i in range(n):
	for j in range(n):
		num[i+1][j+1]+=num[i+1][j]
for i in range(q):
	p,q=map(int,input().split())
	ans=0
	for i in range(p,q+1):
		ans+=num[i][q]-num[i][p-1]
	print(ans)


