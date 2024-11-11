n, *a = map(int, open(0).read().split())
ans = 0
mod = 10 **9 + 7
for k in range(61):
	m = 1 << k
	c = 0
	for x in a:
		if m & x:
			c += 1
	ans +=c * (n - c) * m
	ans %= mod
print(ans)