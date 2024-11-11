t = int(input())

while t:
	n = int(input())

	arr = [int(i) for i in input().split()]

	us = dict()

	for i in arr:
		try:
			us[i] += 1
		except:
			us[i] = 1

	for i in us:
		print(i, end=' ')
	print()

	t -= 1