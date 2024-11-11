
from functools import reduce
n,m=map(int,input().split())
a=reduce(lambda x,y:x+y,[i for i in range(1,n+1)])
x=m%a
if(x==0):
	print(0)
else:
	for i in range(1,n):
		if(x>=i):
			x-=i
		else:
			print(x)
			break