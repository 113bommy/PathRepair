a, b = map(int, input().split())

if a < b:
	print("a < b")
elif b < a:
	print("a > b")
else:
	print("a == b")