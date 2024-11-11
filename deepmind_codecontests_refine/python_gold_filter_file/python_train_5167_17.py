Str = input()
Ln = len(Str)

lastIndex = {}
maxDist = {}

for i in range(Ln):
	if (not Str[i] in lastIndex):
		lastIndex[Str[i]] = i
		maxDist[Str[i]] = i+1
	else:
		maxDist[Str[i]] = max(maxDist[Str[i]], i-lastIndex[Str[i]])
		lastIndex[Str[i]] = i
for i in lastIndex:
	maxDist[i] = max(Ln-lastIndex[i], maxDist[i])

Min = -1
for i in maxDist:
	if (Min == -1 or maxDist[i] < Min):
		Min = maxDist[i]

print (Min)