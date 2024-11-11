y,b=map(int,input().split())
y1,g1,b1=map(int,input().split())
y2=y-(2*y1)
b2=b-(3*b1)
t=y2-g1
z=b2-g1
if t>=0 and z>=0:
	print(t)
elif z>=0 and t<=0:
	print(abs(t))
elif z<=0 and t>=0:
	print(abs(z))
elif z<=0 and t<=0:
	print(abs(z+t))