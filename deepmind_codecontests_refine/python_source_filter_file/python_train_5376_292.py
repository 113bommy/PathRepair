import math
n = int(input())
m = int(input())
if math.log(m, 2)>n:
	print(m%2**n)
else:
	print(m)