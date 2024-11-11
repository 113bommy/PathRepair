t = int(input())

while t:
	n = int(input())

	arr = [int(i) for i in input().split()]

	us = {}

	for i in arr:
		try:
			us[i] += 1
		except:
			us[i] = 1

	for i in us:
		print(us, end=' ')
	print()

	t -= 1