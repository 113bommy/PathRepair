
while True:
	n = int(input())
	if n == 0:
		break
	count = 0
	for i in range(int((n+1)/2)):
		s = 0
		j = i
		while s < n:
			s += j
			j += 1
			if s == n:
				count += 1
	print(count)