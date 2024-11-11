import math
ab=input().split()
a=int(ab[0])
b=int(ab[1])
n=math.log(b/a,1.5)
if(int(n)==n):
	print(n)
else:
	print(math.ceil(n))