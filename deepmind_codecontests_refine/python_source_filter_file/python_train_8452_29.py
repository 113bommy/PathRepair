for _ in range(int(input())):
	n, x, a, b = map(int, input().split())
	a, b = min(a, b), max(a, b)
	if b-a==n-1 and a+n-b<x:
		print(n-1)
	else:
		print(b-a+x)