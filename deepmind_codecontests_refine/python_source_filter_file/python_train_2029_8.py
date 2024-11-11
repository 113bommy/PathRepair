inputString = input()
indexAB, indexBA = [-1 for i in range(2)], [-1 for i in range(2)]

for i in range(len(inputString)-1):
	if (inputString[i] == 'A' and inputString[i+1] == 'B'):
		if (indexAB[0] == -1):
			indexAB[0] = i
		if (indexAB[1] < i):
			indexAB[1] = i

	elif (inputString[i] == 'B' and inputString[i+1] == 'A'):
		if (indexBA[0] == -1):
			indexBA[0] = i
		if (indexBA[1] < i):
			indexBA[1] = i

if ((indexAB[0] == -1) and (indexBA[0] == -1) and ((indexBA[1] - indexAB[0] >= 2) or (indexAB[1] - indexBA[0] >= 2))):
	print ("YES")
else:
	print ("NO")