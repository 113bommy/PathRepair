n, m = [int(x) for x in input().split()]

m = min(n, m)

def check(mid):
	return n + (mid - m) * m - (mid * (mid + 1) // 2 - m * (m - 1) // 2)

l = m
r = 10**10
while (l < r - 1):
	mid = (l + r) // 2
	if (check(mid) > 0):
		l = mid
	else:
		r = mid

for i in range(l, r + 1):
	if (check(i) <= 0):
		print(i)
		exit(0)
