n = int(input())
l = [[int(i) for i in input().split()] for i in range(n)]

for i in range(n):
	s = l[i][0]
	a = l[i][1]
	b = l[i][2]
	c = l[i][3]
	if s < c:
		print(0)
	elif s < a * c:
		print(s // c)
	elif s > a * c:
		print(s // c + (s // (a * c) ) * b)