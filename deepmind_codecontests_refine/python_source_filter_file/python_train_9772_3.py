s = set(list(input()))

if s == {"N", "W"} or s == {"S", "E"} or s == {"N", "W", "S", "E"}:
	print("Yes")
else:
	print("No")