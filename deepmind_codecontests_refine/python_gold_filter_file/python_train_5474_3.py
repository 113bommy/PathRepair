import math
t = int(input())
for cs in range(t):
	x, y, p, q = [int(x) for x in input().split()]
	g, h = math.gcd(x, y), math.gcd(p, q)
	L, R = 0, 1<<100
	if x//g==p//h and y//g==q//h:
		print(0)
	elif p == 0 or p == q or p*R-x > q*R-y:
		print(-1)
	else:
		while L < R-1:
			M = (L + R) >> 1
			if 0 <= p*M-x and p*M-x <= q*M-y:
				R = M
			else:
				L = M
		print(q*R-y)
