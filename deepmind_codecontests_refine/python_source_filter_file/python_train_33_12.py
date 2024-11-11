import math
a,b,c = list(map(int, input().split(" ")))
if a == 0 and b == 0 and c == 0:
	print(-1)
elif a == 0 and b != 0:
	print(1)
	print('{0:.5f}'.format(-c/b))
elif a == 0 and b == 0 and c != 0:
	print(0)
else:
	d = b**2 - 4 * a * c
	if d > 0:
		x1 = (-b + math.sqrt(d))/2*a
		x2 = (-b - math.sqrt(d))/2*a
		if x1 > x2:
			x1,x2 = x2,x1
		print(2)
		print('{0:.5f}'.format(x1))
		print('{0:.5f}'.format(x2))
	elif d == 0:
		x = -b/(2*a)
		print(1)
		print('{0:.5f}'.format(x))
	else:
		print(0)
