N = int(input())
s = set()
for i in range(N):
	a = input
	if a in s:
		s.remove(a)
	else:
		s.add(a)
print(len(s))