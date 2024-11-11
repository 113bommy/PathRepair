def mi():
	return map(int, input().split())

from math import ceil as c
for _ in range(int(input())):
	x,y,p,q = mi()
	bestans = -1
	low = 0
	high = 10**9
	while low<=high:
		mid = (low+high)//2
		p1 = p*mid
		q1 = q*mid
		successful = p1-x
		unsuccessful = q1-y-successful
		if successful<0 or unsuccessful<0:
			low = mid+1
		else:
			high = mid-1
			bestans = successful+ unsuccessful
	print (int(bestans))