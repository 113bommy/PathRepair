n,k=map(int,input().split())
l=list(map(int,input().split()))
s=sum(l)
r=s/n
if(r>=(k-0.5)):
	print(0)
else:
	x=n
	c=0
	for i in range(100000):
		s=s+k
		x=x+1
		c=c+1
		if(s/x>=(k-0.5)):
			print(c)
			break
