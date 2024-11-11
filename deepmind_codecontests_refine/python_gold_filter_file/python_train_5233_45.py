def func():
	l,r = map(int, input().split())
	if (2*l <= r):
		print(l,l*2)
	else:
		print("-1 -1")

for _ in range(int(input())):
	func()