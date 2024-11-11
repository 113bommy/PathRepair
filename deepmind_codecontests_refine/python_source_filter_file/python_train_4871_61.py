import math
a,b=map(int,input().split(' '))

if a==1 or b==1:
	print(0)
else:
	print(math.ceil(a*b/2))
