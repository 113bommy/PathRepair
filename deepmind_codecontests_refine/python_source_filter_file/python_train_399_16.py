# your code goes here
from math import floor
N, X = [int(x) for x in input().split()]

y = N-X
x = X
L = X
while x > 0:
#	k = 2*floor(y/x)
	k, z = divmod(y, x)
	dL = x*(2*k-1)+y
	L += x*(2*k-1)+y
	print(x, y, k, dL)
	y, x = (x, z)

#L += y
print(L)