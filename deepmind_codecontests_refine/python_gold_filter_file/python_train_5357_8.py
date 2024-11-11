p, q, l, r = [int(x) for x in input().split()]
a = ''
b = ''
for i in range(p):
	x, y = [int(x) for x in input().split()]
	a += '0' * (x - len(a))
	a += '1' * (y - x + 1)
for i in range(q):
	x, y = [int(x) for x in input().split()]
	b += '0' * (x - len(b))
	b += '1' * (y - x + 1)
ans = 0
for i in range(l, r + 1):
	ans += 1 if any(map(lambda x: x[0] == '1' and x[1] == '1', zip(a, '0' * i + b))) else 0
print(ans)
