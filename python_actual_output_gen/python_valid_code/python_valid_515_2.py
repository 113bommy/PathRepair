q = int(input())
for _ in range(q):
	s = input()
	t = input()
	b = any(t in s[:i] + s[::-1] for i in range(len(s)))
	print('yes' if b else 'no')