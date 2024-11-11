from sys import stdin as cin

n, k = list(map(int, input().split()))
b, b1, m = [], set(), 0
while n - 1:
	n -= 1
	a = ''
	s = cin.read(1)
	while s != ' ':
		a += s
		s = cin.read(1)
	if a not in b1:
		b.append(a)
		b1.add(a)
		if len(b1) > k:
			b1.discard(b[m])
			m += 1
a = ''
s = cin.read(1)
o = set(map(str, range(10)))
while s in o:
	a += s
	s = cin.read(1)
if a not in b1:
	b.append(a)
	b1.add(a)
	if len(b1) > k:
		b1.discard(b[m])
print(len(b) - m)
print(*b[m:][::-1])
