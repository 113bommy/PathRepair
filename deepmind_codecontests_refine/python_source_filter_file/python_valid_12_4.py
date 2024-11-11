t = int(input())
otv = list()
for i in range(t):
	n, m, k = map(int, input().split())
	if n % 2 == 1:
		k = (m * n) // 2 - k
		k -= (m % 2 * n // 2)
	else:
		k -= (n % 2 * m // 2)
	if k % 2 == 1 or k < 0:
		otv.append('NO')
	else:
		otv.append('YES')
for i in otv:
	print(i)
		
