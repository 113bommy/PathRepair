n, a, b = map(int, input().split())

ans = -1
for x in range(1, min(n, a) + 1):
	y = n - x
	if (y > b or y == 0):
		continue
	ans = max(ans, min(a / x, b / y))
print(ans)