def gcd(a, b):
	while a:
		b %= a
		a, b = b, a
	return b

def lcm(a, b):
	return a // gcd(a, b) * b

n = int(input())
ans = 0
for i in range(n, max(1, n - 200), -1):
	for j in range(i, max(1, i - 200), -1):
		cur = lcm(i, j)
		for k in range(j, max(1, j - 200), -1):
			ans = max(ans, lcm(cur, k))
print(ans)
