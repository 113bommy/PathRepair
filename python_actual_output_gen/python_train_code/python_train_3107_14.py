n, *a = map(int, open(0).read().split())
ans = 0
if a[0] != 0:
	print(-1)
	exit()
for x, y in zip(a, a[1:]):
	if x + 1 < y:
		print(-1)
		exit()
	if x >= y:
		ans += x
print(ans)
