n,a,b,c=map(int,input().split())

z=n%4
if(z==0):
	print(0)
elif(z==1):
	print(min(c,a+b,3*a))
elif(z==2):
	print(min(2*a,b,2*c))
else:
	print(min(a,b+c,3*c))
