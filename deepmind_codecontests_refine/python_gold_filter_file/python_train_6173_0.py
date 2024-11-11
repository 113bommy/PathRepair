t = int(input())
for _ in range(t):
	x, y = map(int, input().split())
	if x == 1:
		print(0, y)
	elif y == 1:
		print(x-1, 1)
	elif y >= x:
		print(x-1, y)
	else:
		x -= 1
		print(x, y)