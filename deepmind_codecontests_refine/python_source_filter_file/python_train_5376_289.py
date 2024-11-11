from math import ceil

n = int(input())
m = int(input())
if n >= 27:	
	print(ceil(m%pow(2,n)))
else:
	print(m)