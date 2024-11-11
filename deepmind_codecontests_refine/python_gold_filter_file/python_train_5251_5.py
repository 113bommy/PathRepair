n, m, minimum, maximum = map(int, input().split())
seq = [int(i) for i in input().split()]
if max(seq) > maximum or min(seq) < minimum:
	print('Incorrect')
else:
	if maximum not in seq and minimum not in seq:
		if n - m >= 2:
			print('Correct')
		else:
			print('Incorrect')
	elif maximum in seq and minimum in seq:
		print('Correct')
	else:
		if n - m >= 1:
			print('Correct')
		else:
			print('Incorrect')