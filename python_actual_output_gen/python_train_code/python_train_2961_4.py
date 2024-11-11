q = int(input())
while q > 0:
	n = int(input())
	add = 0
	if n % 2 == 1:
		n -= 9
		add += 1
	
	if n < 4 and n > 0:
		print(-1)
	else:
		print(n // 4 + add)
	q -= 1