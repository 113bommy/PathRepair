import math
n,m,a,b=map(int,input().split())
if(m*a<=b and n<m):
	print(n*a)
else:
	x=math.floor(n/m)
	y=math.ceil(n/m)
	c=(((n-(x*m))*a)+(x*b))
	d=y*b
	if(c<d):
		print(c)
	else:
		print(d)
