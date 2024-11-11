firstLine = list(map(int,input().split(" ")))
numberElements = firstLine[0]
btc = firstLine[1]
seq = list(map(int,input().split(" ")))

evenTotal = numberElements / 2
oddTotal = evenTotal

evenSeen = 0
oddSeen = 0
totalCuts = 0
possibleCuts = list()
currentCuts = [numberElements]

while True:
	possibleCuts = list()
	evenSeen = 0
	oddSeen = 0
	for i in range(len(seq)):
		nextCut = min(list(filter(lambda x: x >= i, currentCuts)))
		if i == nextCut:
			evenSeen = 0
			oddSeen = 0
	
		if seq[i] % 2 == 0:
			evenSeen += 1
		else:
			oddSeen += 1
		
		if evenSeen == oddSeen and evenSeen > 0 and oddSeen > 0 and i < numberElements - 1 and nextCut - i > 1:
			possibleCuts.append((i, abs(seq[i]-seq[i+1])))
	if len(possibleCuts) == 0:
		break
	minCut = min(possibleCuts, key=lambda item:item[0])
	if btc - minCut[1] >= 0:
		currentCuts.append(minCut[0] + 1)
		btc -= minCut[1]
		totalCuts += 1
	else:
		break
print(totalCuts)
