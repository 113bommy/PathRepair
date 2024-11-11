import math
n, a, b, p, q = map(int, input().split())
lcm = a*b/math.gcd(a, b)
ans = 0
if p >= q:
	ans = n//a*p + n//b*q - n//lcm*q
else:
	ans = n//b*q + n//a*p - n//lcm*p
print(int(ans))