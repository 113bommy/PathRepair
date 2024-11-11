from sys import stdin
input = stdin.buffer.readline

for _ in range(int(input())):
	a, b, c, d = map(int, input().split())
	if a <= b:
		print(b)
		continue
	if c <= d:
		print(-1)
	else:
		print(b + (a - b + c - d - 1) // (c - d) * c)
