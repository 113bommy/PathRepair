n, x = map(int, input().split())
a = list(map(int, input().split()))

ans = sum(a)
b = a[:]
c = [0]*n

for k in range(1, n):
	now = k * x
	for i in range(n):
		tmp = min(b[i-1], a[i])
		now += tmp
		c[i] = tmp
	ans = min(ans, now)
	b = c[:]
	
print(ans)