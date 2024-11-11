from math import pi
d,h,v,e=map(int,input().split())
x=(4*v)/(pi*d*d)
if x<=e :
	print("NO")
else:
	print("YES")
	t=h/(x-e)
	print(t)