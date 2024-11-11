a,b=map(int,input().split())
x=a//2
if x<(b+1):
	print(0,0,n)
else:
	while x>=(b+1) and x%(b+1)!=0:
		x-=x%(b+1)
	if x%(b+1)==0:
		y=x//(b+1)
		s=a-x
		print(y,b*y,1)
	else:
		print(0,0,a)
