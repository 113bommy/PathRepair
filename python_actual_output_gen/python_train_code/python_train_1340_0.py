n, m = map(int, input().split())

def mod_exp(a, b, n):
	x = a
	y = 1
	while b > 0:
		if b%2:
			y = (y*x)%n 
		x = (x*x)%n
		b = b >> 1
	return y

print(mod_exp(3, n, m)-1)