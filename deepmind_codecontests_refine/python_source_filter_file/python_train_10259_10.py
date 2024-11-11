import sys
from math import *

a, b, n, x = map(int, input().split())
inf = int(1e9 + 7)
u = [[x, 1], [0, 0]]
v = [[a, 0], [b, 1]]
multi = lambda u, v: [[sum(a*b%inf for a,b in zip(u_row,v_col)) for v_col in zip(*v)] for u_row in u]

def pow(x, n):
	ans = x
	res = [[1, 0], [0, 1]]
	while n:
		if (n & 1):
			res = multi(res, ans)
		ans = multi(ans, ans)
		n >>= 1
	return res

u = multi(u, pow(v, n))
print(u[0][0])