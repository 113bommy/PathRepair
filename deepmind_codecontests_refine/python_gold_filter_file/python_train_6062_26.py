t = int(input())

for i in range(t):
	l = list(map(int, input().split()))
	m = list(map(int, input().split()))
	s = sum(m[1:])
	if s + m[0] >= l[1]:
		print(l[1])
	else:
		print(m[0] + s)