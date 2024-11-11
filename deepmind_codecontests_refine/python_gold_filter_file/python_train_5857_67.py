t=int(input())
for i in range(t):
	n,r=map(int,input().split())
	count=0
	if r>=n:
		print((((n-1)*(n))//2)+1)
	else:
		print((r*(r+1))//2)
