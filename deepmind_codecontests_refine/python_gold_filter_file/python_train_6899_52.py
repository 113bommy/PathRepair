t = 1
for _ in range(t):
	s = input()
	f = len(s)-2
	print(3)
	print('L', len(s)-1)
	s = s[1:len(s)-1][::-1] + s
	# print(s)
	print('R', len(s)-len(s)//2)

	s = s + s[len(s)//2-1:len(s)-1][::-1]
	# print(s)

	print('R', len(s)-f)

	s = s + s[len(s)-f-1:len(s)-1][::-1]
	# print(s)

