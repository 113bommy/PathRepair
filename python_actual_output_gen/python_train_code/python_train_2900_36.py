for m in range(int(input())):
	nxab = list(map(int, input().split()))
	while nxab[1] != 0 and (min(nxab[2], nxab[3]) != 1 and max(nxab[2], nxab[3]) != nxab[0]):
		if nxab[2] < nxab[3] and nxab[2] > 1:
			nxab[2] -= 1
		elif nxab[3] < nxab[2] and nxab[3] > 1:
			nxab[3] -= 1
		elif nxab[2] < nxab[3] and nxab[2] == 1 and nxab[3] != nxab[0]:
			nxab[3] += 1
		elif nxab[3] < nxab[2] and nxab[3] == 1 and nxab[2] != nxab[0]:
			nxab[2] += 1
		nxab[1] -= 1
	distance = abs(nxab[2] - nxab[3])
	print(distance)