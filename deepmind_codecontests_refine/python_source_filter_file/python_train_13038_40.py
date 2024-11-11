import math
t=int(input())
while(t):
	inp1=list(map(int,input().strip().split()))[:2]
	m,n=inp1[0],inp1[1]
	if(m==n==1):
		print(1)
	elif(m==1):
		if(n % 2):
			print(n//2+1)
		else:
			print(n//2)
	elif(n==1):
		if(m % 2):
			print(m//2+1)
		else:
			print(m//2)
	elif(m % 2):
		val=((m-1)//2)*n+math.ceil(n//2)
		print(val)
	else:
		val=(m//2)*(n)
		print(val)
	t-=1