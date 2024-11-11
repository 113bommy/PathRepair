from math import pi
d,h,v,e=map(int,input().split())
r=d/2
if pi*r**2*e>v:
	print('NO')
else:
	print('YES')
	base=(pi*r**2*h)
	base2=(pi*r**2*e-v)
	print(abs(base/base2))
