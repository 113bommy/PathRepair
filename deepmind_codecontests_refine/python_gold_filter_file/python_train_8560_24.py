def va(h):
	return ((h//2)+10)

t = int(input())

res = []

for i in range(t):
	x,n,m = map(int, input().split())

	if x <= 0:
		res.append('YES')


	while n > 0 and x > 20:
		x = va(x)
		n -= 1


	if x <= 10*m:
		res.append('YES')
	else:
		res.append('NO')


for el in res:
	print(el)