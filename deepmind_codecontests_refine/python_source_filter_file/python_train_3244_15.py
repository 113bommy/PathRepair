t=int(input())
for i in range(0,t):
	n=int(input())
	L=list(map(int,input().split()))
	M=list(map(lambda x:x%3,L))
	a=0
	b=0
	c=0
	for i in range(0,n):
		if(M[i]==0):
			a+=1
		elif(M[i]==1):
			b+=1
		else:
			c+=1

	z=min(a,b)
	y=a+b-2*z
	x=c+z+y//3
	print(x)