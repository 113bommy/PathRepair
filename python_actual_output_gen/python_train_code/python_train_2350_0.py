t=int(input())
while t:
	a,b=map(int,input().split())
	x=len(str(b))
	count=a*(x-1)
	print(count)
	t-=1
		