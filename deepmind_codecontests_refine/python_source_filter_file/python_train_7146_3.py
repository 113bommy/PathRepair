x=input().split()
x=[int(i) for i in x]
d=((x[1]-x[3])**2+(x[2]-x[4])**2)**0.5
if(d!=0):
	cos=(x[1]-x[3])/d
	sin=(x[2]-x[4])/d
	if(d<x[0]):
		print(x[3]+((d+x[0])/2*cos),x[4]+((d+x[0])/2*sin),(d+x[0])/2)
	else:
		print(x[1],x[2],x[0])
else:
	print(x[1]+x[0]/2,x[2],0)