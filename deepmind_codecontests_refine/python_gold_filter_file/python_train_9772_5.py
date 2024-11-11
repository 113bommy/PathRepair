s = set(list(input()))

if s == {"N", "S"} or s == {"E", "W"} or s == {"N", "W", "S", "E"}:
	print("Yes")
else:
	print("No")