n, a, b, c, d = map(int, input().split())


def getResult(n, a, b, c, d):

	count = 0

	for i in range(n):
		if (i + 1) + b - c <= n and (i + 1) + b - c > 0:
			if (i + 1) + a + b - d - c <= n and (i + 1) + a + b - d - c > 0:
				if (i + 1) + a - d <= n and (i + 1) + a + b - d - c > 0:
					count += 1
					#print(i + 1, ",", b, ",", (i + 1) + b - c )
					#print(d, ",", 8, ",",c )
					#print((i + 1) + a - d, ",", d, ",", (i + 1) + a + b - d - c)
					#print()
	print(count * n)

getResult(n, a, b, c, d)
