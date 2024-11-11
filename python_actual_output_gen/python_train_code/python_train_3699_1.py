def f(n, m):
	sz = n
	n -= 1
	step = 2
	print('n = ', n)
	while n > 0:
		n += m
		n = min(n, sz)
		n -= step
		step += 1
		print('n = ', n)
	return step - 1

n, m = map(int, input().split())
m = max(n, m)
cnt = max(n - m, 0)
l = 0
r = 10 ** 18
while l + 1 < r:
    m1 = (l + r) // 2
    x = (m1 * (m1 - 1)) // 2
    if x < cnt:
        l = m1
    else:
        r = m1
print(m - 1 + r)
