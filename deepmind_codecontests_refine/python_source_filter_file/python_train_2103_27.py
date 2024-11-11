import math
for _ in range(int(input())):
	a,b,c,d,k=map(int,str.split(input()))
	x=int(math.ceil(a//c))
	y=int(math.ceil(b//d))
	if x+y<=k:
		print(x,y)
	else:
		print(-1)