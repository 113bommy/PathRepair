y,b,r=map(int,input().split())
x=min(y,b,r)
if r==x:
	d=3*r-3
elif b==x and r!=x:
	d=3*b
else:
	if r-y>=2:
		d=3*y+3
	elif r-y==1:
		d=3*y
print(d)