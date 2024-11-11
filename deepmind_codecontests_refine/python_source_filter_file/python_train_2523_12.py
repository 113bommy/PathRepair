t = int(input())
for _ in range(t):
	x, y = [int(i) for i in input().split(' ')]
	a, b = [int(i) for i in input().split(' ')]
	count = 0
	if x < y:
		x, y = y, x 	
	d = x - y
	if d <= a:
		count = (x - y) * a + y * b
	else:
		count = a * (x + y)	
	print(count)
