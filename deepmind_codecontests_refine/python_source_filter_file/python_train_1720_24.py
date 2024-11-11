import math
n = int(input())
k = (math.sqrt(8*n+1)-1)/2
k = int(k)
d = (1 + k)*k/2
print(k)
if n == d:
	print(k)
else:
	print(int(n - d))