def sol():
	l = 0
	r = 0
	s = 0
	for i in range(1,n):
		if problems[i] <= 2 * problems[i-1]:
			r += 1
		else:
			s = max(s, r-l+1)
			l = i
			r = i
	s = max(s, r-l+1)
	return s


n = int(input())
problems = [int(x) for x in input().split(' ')]
print(sol())
