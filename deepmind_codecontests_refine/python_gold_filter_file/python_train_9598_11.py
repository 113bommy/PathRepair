
n,a,b=map(int,input().split())
if(n==a+b):
	print(b)
elif(n>a+b):
	print(b+1)
else:
	print(n-a)