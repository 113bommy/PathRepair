t = int(input())
while t > 0:
	t -= 1
	a = input().split(' ')

	x = int(a[0])
	y = int(a[0])

	if x == 1 or y == 1:
		print("YES")
	elif (x == 2 and y <= 2) or (x <= 2 and y == 2):
		print("YES");
	else:
		print("NO")