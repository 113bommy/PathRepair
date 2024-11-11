n = int(input())
for i in range(n):
	x, y = list(map(int, input().split()))
	c = [0] + list(map(int, input().split()))
	p1 = abs(x) * c[3 if x < 0 else 6] + abs(y) * c[5 if y < 0 else 2]
	p2 = abs(y) * c[4 if y < 0 else 1] + abs(x - y) * c[3 if x - y < 0 else 6]
	p3 = abs(y) * c[4 if y < 0 else 1] + abs(y - x) * c[5 if y - x < 0 else 2]
	print(min((p1, p2, p3)))
