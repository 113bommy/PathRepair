a, b, c = map(int, input().split())

if max(a, b, c) == a:
	print(0 if a < b + c else a - (b + c) + 1)
elif max(a, b, c) == b:
	print(0 if b < a + c else b - (a + c) + 1)
else:
	print(0 if c < a + b else c - (b + c) + 1)