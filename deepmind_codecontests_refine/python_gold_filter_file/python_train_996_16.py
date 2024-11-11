def gcd(a, b):
	while(b > 0):
		r = a % b
		a = b
		b = r
	return a
a, b = map(int, input().split())
c, d  = map(int, input().split())
if((d - b) % gcd(a, c) != 0):
	print(-1)
else:
	i = 0
	while(True):
		j = (b + i * a - d) // c
		if (j >= 0 and (b + i * a - d) % c == 0):
			print(b + i*a)
			break
		i += 1