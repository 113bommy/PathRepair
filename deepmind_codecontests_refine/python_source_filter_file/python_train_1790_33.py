q = int(input())
while q > 0:
	n = int(input())
	if n == 2:
		print(0)
	if n!= 2:
		if n % 2 == 0:
			print(0)
		if n % 2 > 0:
			print(n%2)
	q = q - 1
