n, m, k=map(int, input().split())
if k >= m:
	print(1)
elif k < m <= k + n:
	ans = 1
	for i in range(k + 1):
		ans *= (m - i) / (n + 1 + i)
	print(1 - ans)
else:
	print(1)
