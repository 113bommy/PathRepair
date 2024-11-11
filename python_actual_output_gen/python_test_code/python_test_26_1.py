def find(n, l, r, x, contests, lista):
	if n == 0:
		s = sum(lista)
		if s >= l and s <= r and max(lista)-min(lista) >= x:
			return 1
		else:
			return 0
	c = 0
	for i in range(len(contests)):
		c += find(n-1, l, r, x, contests[i+1:], lista+[contests[i],])
	return c


n, l, r, x = list(map(int, input().split()))
contests = list(map(int, input().split()))
c = 0
for i in range(2, n):
	c += find(i, l, r, x, contests, [])
print(c)