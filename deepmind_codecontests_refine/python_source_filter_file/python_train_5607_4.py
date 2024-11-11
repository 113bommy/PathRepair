
x, y = map(int, input() .split())


if y > x:
	if x*y > 0:
		a = y-x
	else:
		a = abs(abs(x) - abs(y)) + 1
else:
	if x*y > 0:
		a = abs(abs(x) - abs(y)) + 2
	else:
		a = abs(abs(x) - abs(y)) + 1

print (a)


