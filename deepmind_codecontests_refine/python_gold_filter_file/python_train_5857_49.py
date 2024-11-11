t=int(input())
while t>0:
	t-=1
	n,r=map(int,input().split())
	if r<n:
		k=(r*(r+1))//2
		print(int(k))
	else:
		z=(n*(n+1))//2+(1-n)
		print(int(z))