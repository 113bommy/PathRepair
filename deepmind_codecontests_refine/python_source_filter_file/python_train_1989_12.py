if __name__ == '__main__':
	n = int(input())
	m = int(input())
	benchList = []
	for i in range(0, n):
		benchList.append(int(input()))

	if len(benchList) > 1:
		benchList.sort()
		benchListAct, minMax = [benchList[0] + m] + benchList[1:], 500
		for i in range(0, m + 1):
			minMax = min(minMax, max(benchListAct))
			benchListAct[0] -= 1
			benchListAct[1] += 1
			benchListAct = [benchListAct[0]] + sorted(benchListAct[1:])
		print(minMax, benchList[-1] + m)
	else:
		print(benchList[0] + m, benchList[0] + m)