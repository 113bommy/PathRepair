import math

n,p,w,d=map(int,input().split())
z=0
left=n
x=0
while(z<=w) :
	left=p-z*d
	if(left%w==0) :
		x=left//w
		break
	z+=1
if(x+z>n) :
	print("-1")
elif(x==0 and z*d!=p) :
	print("-1")
else :
	print(x,z,n-x-z)

	
	