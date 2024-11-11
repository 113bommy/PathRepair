n,m,k = list(map(int, input().split()))
a = list(map(int, input().split()))

m1, m2 = 1, 1
for x in a:
	if x > m2:
		if x > m1:
			m2 = m1
			m1 = x
		else:
			m2 = x
print(m1 * m - ((m+1) // (k+1)) * (m1 - m2))
