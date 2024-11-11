s = input()
if s.count('a') == 1:
	print(1)
else:
	print((2 * s.count('a') - 1, len(s))[s.count('a') > len(s) // 2])
