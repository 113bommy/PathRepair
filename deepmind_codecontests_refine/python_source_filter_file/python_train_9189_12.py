t = int(input())
for _ in range(t):
	x1, y1, x2, y2 = map(int, input().split())
	a = abs(x2-x1 + y2-y1)
	if x1 != x2 and y1 != y2:
		a += 2
	print(a)