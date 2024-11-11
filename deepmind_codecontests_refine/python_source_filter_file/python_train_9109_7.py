import copy

def main():
	temp = input().split()
	(n, x1, y1, x2, y2) = (int(x) for x in temp)
	points = []
	for i in range(n):
		temp = input().split()
		(x, y) = (int(k) for k in temp)
		points.append((x, y))
	print(x1, y1, x2, y2, points)
	print(solver(x1, y1, x2, y2, points))

def solver(x1, y1, x2, y2, points):
	distances = set()
	for (x, y) in points:
		d1 = squareDistance(x1, y1, x, y)
		d2 = squareDistance(x2, y2, x, y)
		distances.add((d1, d2))
	list1 = list(distances)
	list2 = copy.copy(list1)
	list1.sort(key = lambda point: point[0])
	list2.sort(key = lambda point: point[1])
	indices = {list2[i]: i for i in range(len(list2))}
	#print(list1, list2)
	# start algorithm
	# set min(r1**2 + r2**2) to a high value, where r1 = 0
	minValue = list2[len(list2)-1][1]
	#print(minValue)
	# initially let r2 must cover every point and
	# r1 has radius 0
	booleans = [True] * len(list2)
	index2 = len(list2) - 1
	for i in range(len(list1)):
		pair = list1[i]
		r1 = pair[0]
		booleans[indices[pair]] = False
		#print(booleans)
		while index2 >= 0 and booleans[index2] == False:
			index2 -= 1
		if index2 == -1:
			value = r1
			if value < minValue:
				minValue = value
		else:
			r2 = list2[index2][1]
			value = r1 + r2
			if value < minValue:
				minValue = value
	return minValue



def squareDistance(x1, y1, x2, y2):
	leg1 = abs(x1 - x2)
	leg2 = abs(y1 - y2)
	return leg1**2 + leg2**2

#print(squareDistance(2, 1, 6, 7))


#print(solver(-1, 0, 5, 3, [(0, 2), (5, 2)]))
#print(solver(0, 0, 5, 0, [(9, 4), (8, 3), (-1, 0), (1, 4)]))