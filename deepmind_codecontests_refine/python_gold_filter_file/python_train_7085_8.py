while True:
	s = input()
	if s == "-":
		break
	m = int(input())
	for n in range(m):
		h = int(input())
		s = s[h:] + s[0: h]
	print(s)