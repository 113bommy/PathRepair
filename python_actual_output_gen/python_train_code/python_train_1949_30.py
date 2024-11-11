a,b = map(int,input().split())
if a < b:
	if a * b < 0:
		print(abs(abs(a) - b) + 1)
	else:
		print(b - a)
else:
	if a * b < 0:
		print(abs( a - abs(b)) + 1)
	else:
		print(2 + abs(a - b))