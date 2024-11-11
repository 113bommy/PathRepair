n=int(input())
y=(-1+(1+8*n)**0.5)/2
x=int(y)
if(x==y):
	print(y)
else:
	print(n-x*(x+1)//2)