n,k = map(int,input().split())

s=n*(n+1)/2
if k>s:
	k=k%s
	k=int(k)
if k==0:
	print(0)
else:

	y= -1+(1+8*k)**(0.5)
	y=y/2
	y=int(y)
	k=k-(y*(y+1))//2
print(k)
