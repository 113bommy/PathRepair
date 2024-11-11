n = int(input())
if n % 2 == 0:
	print(n//2)
else:
	i = 3
	k = n
	while i < k and n % i != 0:
		i  += 1
		k = n // i 
	if k <= i:
		print(1)
	else:
		n -= i
		print(n//2 + 1)
