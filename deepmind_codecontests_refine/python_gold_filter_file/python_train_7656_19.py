def filya_and_homework():
	no_elements = int(input())
	elements = set([int(x) for x in input().split(' ')])

	if len(elements) >= 4:
		print('NO')
	elif len(elements) == 1 or len(elements) == 2:
		print('YES')
	else:
		# len = 3
		elements = sorted(list(elements))
		if 2 * elements[1] == elements[0] + elements[2]:
			print('YES')
		else:
			print('NO')



filya_and_homework()

