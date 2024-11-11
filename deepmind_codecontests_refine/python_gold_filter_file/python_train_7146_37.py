
R,x1,y1,x2,y2=input().split()
R=float(R)
x1=float(x1)
y1=float(y1)
x2=float(x2)
y2=float(y2)
d=((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))**0.5
k1=d;
k2=(R-d)/2;
if d==0:
	print(x1+R/2,y1,R/2)
elif d<=R:
	print((x1*(k1+k2)-k2*x2)/k1,(y1*(k1+k2)-k2*y2)/k1,(R+d)/2)
else:
	print(x1,y1,R)
