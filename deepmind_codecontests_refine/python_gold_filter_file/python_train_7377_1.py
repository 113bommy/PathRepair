numdict = dict()
while True:
	try:
		num = input()
		if num not in numdict:
			numdict[num] = 0
		else:
			numdict[num] += 1
	except EOFError:
		break
most = max(numdict.values())
mostlist = list()
for key in numdict:
	if most == numdict[key]:
		mostlist.append(int(key))
mostlist.sort()
for item in mostlist:
	print(item)