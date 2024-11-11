l,r,a=map(int,input().split())
if l==r:
	print(2*l+(a//2)*2)
else:	
	if l>r:
		l,r=r,l
	if  r-l>=a:
		print((l+a)*2)
	else:
		print(2*r+(a//2)*2)