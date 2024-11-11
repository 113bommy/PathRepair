n = int(input())
xy = [int(i) for i in input().split()]
lengthW = 0
lengthB = 0
if (xy[0] < xy[1]):
	lengthW += xy[0]-1+(xy[1]-xy[0])
else:
	lengthW += xy[1]-1+(xy[0]-xy[1])
xy[0] = n+1-xy[0]
xy[1] = n+1-xy[1]
if (xy[0] < xy[1]):
	lengthB += xy[0]-1+(xy[1]-xy[0])
else:
	lengthB += xy[1]-1+(xy[0]-xy[1])
if (lengthW <= lengthB):
	print("White")
else:
	print("Black")