import itertools
n,m=map(int,input().split())
l=[i for i in range(1,n+1)]
a=itertools.cycle(l)
if(n>1):
	for i in range(m):
		b=next(a)
		if(b>m):
			print(m)
			break
		else:
			m=m-b
if(n==1):
	print(0)
