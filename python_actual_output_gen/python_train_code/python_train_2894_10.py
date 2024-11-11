n, x = map(int, input().split())
a = list(map(int, input().split()))

c = 0
for i in range(n-1):
	t = a[i] + a[i+1] - x
	a[i+1] -= t
	if a[i+1] < 0:
		a[i] += a[i+1]
		a[i+1] = 0
	c += t
print(c)