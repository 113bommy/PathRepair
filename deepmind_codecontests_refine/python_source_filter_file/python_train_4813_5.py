from sys import stdin
input = stdin.buffer.readline
last = []
for _ in range(int(input())):
	t = int(1e9)
	A, B, C = map(int, input().split())
	for a in range(1, 10001):
		for b in range(a, 10001, a):
			c = (C // b) * b
			c = (c if abs(c-C) < abs(c+b-C) else c+b)
			x = abs(a-A) + abs(b-B) + abs(c-C)
			if x < t:
				t = x
				(u, v, w) = (a, b, c)
	last.append(str(t))
	last.append(' '.join([str(u), str(v), str(w)]))
print('\n'.join(last))