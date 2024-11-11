for i in range(int(input())):
	a, b = map(int, input().split())
	print((len(str(b)) - 1) * a)