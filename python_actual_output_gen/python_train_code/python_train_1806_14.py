n = int(input())

l = [2, 3, 4, 5, 6, 7, 8, 9]

if n <= 10:
	print(0)
elif 11 == n or 21 == n:
	print(1)
elif 20 == n:
	print(15)
else:
	for i in l:
		if n == 10 + i:
			print(4)
			break
	else:
		print(0)