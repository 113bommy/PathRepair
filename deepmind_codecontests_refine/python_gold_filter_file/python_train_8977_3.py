t = int(input())
for _ in range(t):
	x = int(input())
	p2 = 1
	ans = 0
	while p2 <= x:
		ans += x // p2
		p2 *= 2
	print(ans)
