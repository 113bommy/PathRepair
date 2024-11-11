n, x = map(int, input().split())
nm = 0
for i in range(n):
	a, b = map(str, input().split())
	if (a == "+"):
		x += int(b)
	else:
		b = int(b)
		if (x > b):
			x -= b
		else:
			nm += 1
print(x, nm)