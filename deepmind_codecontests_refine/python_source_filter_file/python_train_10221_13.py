from math import gcd

n, m, q = map(int, input().strip().split())
g = gcd(n, m)
f0, f1 = n / g, m / g
for _ in range(q):
	sx, sy, ex, ey = map(int, input().strip().split())
	if sx == 1:
		b00 = (sy-1) // f0
	else:
		b00 = (sy-1) // f1
	if ex == 1:
		b10 = (ey-1) // f0
	else:
		b10 = (ey-1) // f1
	if b00 == b10:
		print("YES")
	else:
		print("NO")
