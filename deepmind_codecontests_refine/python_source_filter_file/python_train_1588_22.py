from math import sin,pi
for _ in range(int(input())):
	n = int(input())
	angle = pi/(2*n)
	ans = 1/sin(angle)	
	print("{:.9f}".format(ans))