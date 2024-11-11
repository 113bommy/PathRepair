n = int(input())
a = input()
res = []
num_set = set('2357')
for digit in a:
	if digit in num_set:
		res.append(digit)
	elif digit == '4':
		for num in '223':
			res.append(num)
	elif digit == '6':
		res.append('3')
		res.append('6')
	elif digit == '8':
		for num in '2227':
			res.append(num)
	elif digit == '9':
		for num in '2337':
			res.append(num)
print(''.join(sorted(res, reverse=True)))
