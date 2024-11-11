t = int(input())
for i in range(t):
	n = int(input())
	b = list(map(int , input().split()))
	leftpositive = 0
	leftnegative = 0
	for j in range(len(b) - 1):
		if b[j] > 0 and b[j+1] < 0:
			if abs(b[j]) > abs(b[j+1]):
				b[j] = b[j] + b[j+1]
				b[j+1] = 0
				leftpositive = leftpositive + b[j]
			elif abs(b[j]) < abs(b[j+1]):
				b[j+1] = b[j+1] + b[j]
				b[j] = 0
			else:
				b[j] = 0
				b[j+1] = 0
		elif b[j] < 0 and leftpositive > 0:
			if abs(b[j]) > leftpositive:
				b[j] = b[j] + leftpositive
				leftnegative = leftnegative + b[j]
				leftpositive = 0
			elif abs(b[j]) < leftpositive:
				leftpositive = leftpositive + b[j]
				b[j] = 0
			else:
				leftpositive = 0
				b[j] = 0
		elif b[j] > 0  and b[j+1]> 0:
			leftpositive = leftpositive + b[j]
		else:
			leftnegative  = leftnegative + b[j]
	print(abs(leftnegative) , end = '\n')
