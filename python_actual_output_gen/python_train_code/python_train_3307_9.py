n, k = map(int, input().split())
a = list(map(int, input().split()))

ans = -1
for c in range(n):
	temp = [x[1] for x in enumerate(a) if (x[0] - c) % k == 0]
	e = temp.count(1)
	s = temp.count(-1)
	ans = max(abs(e - s), ans)

print(n - ans)
