import sys
input=sys.stdin.buffer.readline
for _ in range(int(input())):
	n=int(input())
	ans,x,y=0,10**9,(0,0)
	a0,b0=map(int,input().split())
	for i in range(1,n):
		a,b=map(int,input().split())
		k=max(0,a-b0)
		ans+=k
		if a-k<x:x=a-k;y=(a,k)
		b0=b
	k=max(0,a0-b0)
	ans+=k
	if a0-k<x:x=a0-k;y=(a0,k)
	ans+=y[0]-y[1]
	print(ans)