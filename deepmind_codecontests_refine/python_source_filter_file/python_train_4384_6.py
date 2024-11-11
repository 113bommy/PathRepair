n, m, h = map(int,input().split())
s = 0
for i in range(1, h + 1):
	n = n - 4 * (i - 1)
	m = m - 4 * (i - 1)
	s += 2 * (n + m) - 4
print(s)
