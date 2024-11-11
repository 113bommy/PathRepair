import math
a = [int(i) for i in input().split()]
if(math.fabs(a[0]-a[1])<=1):
	print(2*a[2]+max(a[0],a[1]))
else:
	print(2*a[2]+min(a[0],a[1]))