for _ in range(int(input())):
	n = int(input())
	a = list(map(int, input().split()))
	b = list(map(int, input().split()))
	amin, bmin = min(a), min(b)
	res = 0
	for i in range(n):
		x, y = abs(a[i]-amin), abs(b[i] - bmin)
		res += abs(x - y) + min(x, y)
	print("ANS", res)
