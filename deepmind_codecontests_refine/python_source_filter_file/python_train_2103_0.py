for x in range(int(input())):
	a,b,c,d,k=map(int,input().split())
	if a%c==0:
		x=a//c
	else:
		x=(a//c)+1
	if b%d==0:
		y=b//c
	else:
		y=(b//d)+1
	if x+y<=k:
		print(x,y)
	else:
		print(-1)