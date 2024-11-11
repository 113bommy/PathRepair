import sys
inputData = sys.stdin.readlines()

inputData = inputData[1].split()
inputData = [int(x) for x in inputData]

min1 = 0
min2 = 0

pos1 = 1
pos2 = 10**6

for i in inputData:
	if(i - 10**6 > min2):
		min2 = i - 10**6
		pos2 = 10**6 + i
min1 = min2
pos1 = min1

inputData = [x for x in inputData if x > min1]

centerPoint = (10**6 + 2*min1)/2

close1 = close2 = 1 << 30


for i in inputData:
	
	if(abs(i - centerPoint) < close1 and i <= centerPoint):
		close1 = abs(i -  centerPoint)
		min1 += i - min1
		
	elif (abs(i - centerPoint) < close2 and i > centerPoint):
		close2 = abs(i - centerPoint)
		min2 += pos2 - i
		pos2 = i


		
print(max(min1 - 1, min2))