elems, median = [int(x) for x in input().split()]
array = [-1] + sorted([int(y) for y in input().split()])
first = 0
last = 0
try:
	first = array.index(median) 
	last = elems - array[::-1].index(median)
except ValueError:
	pass

midPt = (elems + 1)//2

# print(first, last)
if first == 0 and last == 0:
	# print("Did not find")
	insertIndex = elems + 1
	newEnd = elems + 1
	for i in range(1, elems + 1):
		if array[i] > median:
			insertIndex = i
			break
	newMidPt = (elems+2)//2
	newElems = elems + 1
	print(insertIndex, newMidPt)
	if insertIndex == newMidPt:
		print(1)
	elif insertIndex < newMidPt:
		if newElems % 2 == 1:
			print((newMidPt - insertIndex)*2)
		else:
			print((newMidPt - insertIndex)*2 + 1)		
	elif insertIndex > newMidPt:
		if newElems % 2 == 1:
			print((insertIndex - newMidPt)*2 + 1)
		else:
			print((insertIndex - newMidPt)*2)
	# print("Insert index: ", insertIndex)
	# if insertIndex == elems + 1:
	# 	print(elems + 1)
	# else:
	# 	if elems % 2 == 1:
	# 		print(max(elems + 1 - insertIndex, insertIndex - 1) - min(elems + 1 - insertIndex, insertIndex - 1))
	# 	else:
	# 		print(max(elems + 1 - insertIndex, insertIndex - 1) - min(elems + 1 - insertIndex, insertIndex - 1))
else:
	if array[midPt] == median:
		print(0)
	elif last < midPt:
		if elems % 2 == 1:
			print((midPt - last)*2 - 1)
		else:
			print((midPt - last)*2)
	elif first > midPt:
		if elems % 2 == 1:
			print((first - midPt)*2)
		else:
			print((first - midPt)*2 - 1)