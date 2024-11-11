n = int(input())
a = [*map(int, input().split())]

from math import gcd
from functools import reduce

g = reduce(gcd, a)
print('YES')

if g > 1:
	print(0)
else:
	ans = 0
	c = 0

	for i in a:
		if i & 1:
			c += 1
		else:
			ans += c // 2 + 2 * c & 1
			c = 0

	ans += c // 2 + 2 * c & 1
	print(ans)