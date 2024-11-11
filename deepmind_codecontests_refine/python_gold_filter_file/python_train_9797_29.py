n, k = map(int, input().split())
t = n // (2 * k + 1)
left = n % (2 * k + 1)
print(t + (1 if left > 0 else 0))
for i in range(((1 if left > 0 else k + 1) if left <= k else left - k), n + 1, 2 * k + 1):
	print(i, end=' ')