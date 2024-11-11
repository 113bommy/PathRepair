def check(n, m, s, v):
	mi = 0
	for i in range(n):
		if v[i]+s<mi:
			return False
		if v[i]>mi:
			if (v[i]+s)%m>=mi:
				if v[i]<(v[i]+s)%m:
					mi = v[i]
			else:
				mi = v[i]

		# print(i, mi)
	return True

if __name__ == "__main__":	
	n, m = list(map(int, input().split()))
	v = list(map(int, input().split()))
	
	l = 0
	r = m
	while l<r:
		s = (l+r)//2
		if check(n, m, s, v):
			# print(s, 1)
			r = s
		else:
			# print(s, 0)
			l = s+1

	print(l)
	