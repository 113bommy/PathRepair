n, t = map(int, input().split())

ans = 0

for day in input().split():
	ans += 1
	n -= 86400 - int(day)
	if n <= 0:
		print(ans)
		break