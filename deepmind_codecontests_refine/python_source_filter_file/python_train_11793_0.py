n,R,r=map(int,input().split())
if R<(2*r):
	if r<=R and n==1:
		print("YES")
	else:
		print("NO")
else:
	from math import asin,pi
	theta = 2*asin(r/(R-r))
	m=2*pi/theta
	print(n,m,theta,pi)
	if n<=(m+1e-9):
		print("YES")
	else:
		print("NO")

