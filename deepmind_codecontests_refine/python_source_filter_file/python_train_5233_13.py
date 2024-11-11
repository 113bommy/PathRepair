from sys import stdin
input = stdin.buffer.readline
for _ in range(int(input())):
	l, r = map(int, input().split())
	if r < l * 2:
		print(-1)
	else:
		print(l, l * 2)
