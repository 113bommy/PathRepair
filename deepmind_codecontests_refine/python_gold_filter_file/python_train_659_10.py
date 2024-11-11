def potatoes(y, k ,n):
	arr = list(range(k, n+1, k))
	arr = [i - y for i in arr if i-y >= 1]
	if len(arr) > 0:
		print(*arr)
	else:
		print(-1)

y, k, n = map(int, input().split())
potatoes(y, k ,n)