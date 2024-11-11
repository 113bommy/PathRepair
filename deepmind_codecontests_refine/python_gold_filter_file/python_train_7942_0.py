
from math import *
t=int(input())
for i in range(t):
	n=int(input())
	temp=int(sqrt(2*n-1))
	if n<5:
		print(0)
	else:
		if temp%2==0:
			if ((temp-1)**2+1)/2<=n:
				print(int(temp/2)-1)
		else:
			if (temp**2+1)/2<=n:
				print(int(floor(temp/2)))

