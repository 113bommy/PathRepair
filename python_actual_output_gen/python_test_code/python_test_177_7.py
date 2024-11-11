l, r = map(int, input().split())

ans = 0

for i in range(30):
	for j in range(30):
		q = 2 ** i * 3 ** j
		if l <= q and q <= r:
			ans += 1

print(ans)
