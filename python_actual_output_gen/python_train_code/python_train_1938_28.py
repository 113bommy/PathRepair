n,a,b,c = map(int,input().split())
d = n%4
if d==0:
	print(0)
elif d==1:
	print(min(c,3*b,3*a))
elif d==2:
	print(min(c*2,b,2*a))
else:
	print(min(3*c,a))