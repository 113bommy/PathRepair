n, m = map(int, input().split())
k, x, y = 0, (n - 1) * n / 2, sum(abs(i - (n + 1) // 2) for i in range(1, n + 1))
for i in range(m):
	a, b = map(int, input().split())
	k += a * n + max(b * x, b * y)
print(k / n)