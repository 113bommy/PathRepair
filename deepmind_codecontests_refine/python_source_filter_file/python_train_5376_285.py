import math
n=int(input())
m=int(input())
c=math.log(m,2)
if c>n:
	print(m%(2**n))
else:
	print(m)