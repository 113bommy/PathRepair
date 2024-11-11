import math

inp = [int(x) for x in input().split()]

R  = inp[0]
x1 = inp[1]
y1 = inp[2]
x2 = inp[3]
y2 = inp[4]

d = math.sqrt((x2 - x1)**2 + (y2 - y1)**2)

if d >= R:
	print(x1, y1, R)

elif d < 10**(-7):
	x3 = x2 - R/4.0
	y3 = y2
	print(x3, y3, R/4.0)

else:
	r  = (d + R)/2.0
	x3 = (1.0 - r/d)*x2 + (r/d)*x1
	y3 = (1.0 - r/d)*y2 + (r/d)*y1
	print(x3, y3, r)
	