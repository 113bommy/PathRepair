t=int(input())
a=[]
for i in range(t):
	blank=list(map(str, input().split()))
	x=list(map(int, input().split()))
	y=list(map(int, input().split()))
	f=list(map(int, input().split()))
	if(x[0]==y[0] and x[0]==f[0] ):
		if((f[1]-x[1])*(f[1]-y[1])<0):
			n=abs(y[1]-x[1]) +2
		else:
			n=abs(y[1]-x[1])
	elif(x[1]==y[1] and x[1]==f[1] ):
		if((f[0]-x[0])*(f[0]-y[0])<0):
			n= abs(y[0]-x[0])+2
		else:
			n=abs(y[0]-x[0])
	else:
		n= abs(y[0]-x[0])+(y[1]-x[1])
	a.append(n)
for i in range(t):
		print(a[i])
		
	
	