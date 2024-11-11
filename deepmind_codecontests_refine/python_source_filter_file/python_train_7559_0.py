from sys import stdin
input=lambda : stdin.readline().strip()
from math import ceil,sqrt,factorial,gcd
from collections import deque
n,m,k=map(int,input().split())
dp=[[float("infinity") for i in range(m)] for i in range(n)]
l=[]
for i in range(n):
	l.append(list(input()))
x1,y1,x2,y2=map(lambda a:int(a)-1,input().split())
t=[(1,0),(0,1),(0,-1),(-1,0)]
q=deque()
q.append((x1,y1))
dp[x1][y1]=0
while q:
	x,y=q.popleft()
	if x==x2 and y==y2:
		# print(90)
		break
	for a,b in t:
		for i in range(1,k+1):
			e=x+i*a
			f=y+i*b
			if e<0 or e>=n or f>=m or f<0 or l[e][f]!="." or dp[e][f]<=dp[x][y]+1:
				# print(e,f)
				break
			else:
				if dp[e][f]>dp[x][y]+1:
					dp[e][f]=dp[x][y]+1
					q.append((e,f))
	# print(q)
ans=dp[x2][y2]
if ans==float("infinity"):
	ans=-1
print(ans)
