import math,collections
for _ in range(int(input())):
	n=int(input())
	g=math.sqrt(n)
	x=int(g)
	h=n**(1/3)
	y=int(h)+math.isclose(1000,h,rel_tol=1e-10)
	b=collections.defaultdict(int)
	for k in range(1,y+1):
		b[k**3]=1
	c=0
	for l in range(1,x+1):
		c+=b[l**2]
	print(x+y-c)