z,x,c=map(int,input().split())
if (z+x)>c:
	if x>=z and x>=c:
		d=2*(z+c)
	elif z>=x and z>=c:
		d=2*(x+c)
	else:	
		d=x+z+c
if z+x<=c:
	d=2*z+2*x
print(d)		
