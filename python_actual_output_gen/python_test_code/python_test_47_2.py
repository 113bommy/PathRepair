n, m = map(int, input().split())

b = list(map(int, input().split()))
g = list(map(int, input().split()))


x = max(b)


y = min(g)


if x > y:
	print(-1)

elif x == y:
	print(sum(b) * m + sum(g) - x * m)

else:
	
	m1, m2 = 0, 0
	
	for c in b:
		if c >= m1:
			m1, m2 = c, m1
		elif c >= m2:
			m2 = c
	print(m1, m2)
	print(sum(b) * m + sum(g) - x * (m - 1) - m2)
