import math

la, ra, ta = map(int, input().split())
lb, rb, tb = map(int, input().split())

def f(la, ra, ta, lb, rb, tb):
	d = la - lb
	x = math.gcd(ta, tb)
	d = ((d % x) + x) % x
	return min(ra, rb - d)

ra = ra - la + 1
rb = rb - lb + 1
print(max(f(la, ra, ta, lb, rb, tb), f(lb, rb, tb, la, ra, ta)))