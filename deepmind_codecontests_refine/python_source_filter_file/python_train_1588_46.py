from math import pi, cos

for _ in range(int(input())):
	n = int(input())
	angle = (pi/2) * ((n-1)/n)
	print(1/cos(angle))
