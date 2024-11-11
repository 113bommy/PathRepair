
for _ in range(int(input())):
	a, b, c = map(int, input().split())

	print(1 if a < b else -1, c if b < a * c else -1)
