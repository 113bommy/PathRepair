
n=int(input())
for i in range(n):
	a,b,c,d,k=map(int,input().split())
	x=a//c
	y=b//d
	if(a%c!=0):
		x+=1
	if(y%d!=0):
		y+=1
	if(x+y>k):
		print("-1")
	else:
		print(x,y)
