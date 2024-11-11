n = int(input())
a = [int(s) for s in input().split()]
d = 0
ans = 0
mod = 10**9+7
for d in range(60):
	c0 = 0
	c1 = 0
	for v in a:
		if v >> d & 1:
			c1 += 1
		else:
			c0 += 1
	ans = (ans + (c0 * c1 << d)) % mod
print(ans)