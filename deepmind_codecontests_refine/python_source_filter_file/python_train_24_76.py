# only gravity will pull me down

from collections import *

from math import *

for _ in range(int(input())) :
	n = int(input())
	a = list(map(int, input().split()))
	f = 0

	a.sort()
	if a[n-1] > (a[0] + a[1]) :
		print(1, 2, n)
	else :
		print(-1)

	

