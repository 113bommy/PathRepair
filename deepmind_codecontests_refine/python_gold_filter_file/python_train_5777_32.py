n = int(input().strip())
if n == 2:
	print(1)
	print(1)
elif n == 3:
	print(2)
	print(1, 3)
elif n == 4:
	print(4)
	print(3, 1, 4, 2)
else:
	arr = [i for i in range(1, n+1, 2)] + [i for i in range(2, n+1, 2)]
	print(len(arr))
	print(*arr)
