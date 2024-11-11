n, m = map(int ,input().split())
if m <= n:
	print((m - 1) // 2)
elif m >= n + n:
	print(0)
else:
	print((n + n - m + 1) // 2)
