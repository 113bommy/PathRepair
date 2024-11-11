
n, l, a = map(int, input().split())
m, x = 0, 0
for _ in range(n):
	t, li = map(int, input().split())
	m += (t - x) // a
	x += t + li

m += (l - x) // a
print(m)