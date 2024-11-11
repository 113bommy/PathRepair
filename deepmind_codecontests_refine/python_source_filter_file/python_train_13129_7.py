def retarray():
	return list(map(int, input().split()))

t = int(input())
for _ in range(t):
	n, x, y, d = retarray()
	
	res = -1

	if abs(x-y) % d == 0 :
		res = abs(x-y)//d

	else:
		if (y - 1) % d == 0 :
			res = x//d + (y-1)//d + 1 if x%d else 0

		if (n - y) % d == 0:
			if not res == -1:
				res = min((n-y)//d + (n-x)//d + 1 if (n-x)%d else 0, res)
			else:
				res = (n-y)//d + (n-x)//d + 1 if (n-x)%d else 0

	print(res)
