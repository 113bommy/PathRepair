while True:
	W = list(input())
	if W[0] == '-':
		break
	times = int(input())
	for i in range(times):
		h = int(input())
		W = W[h:]+W[0:h]
	print(*W, sep='')