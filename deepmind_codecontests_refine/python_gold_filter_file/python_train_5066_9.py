if __name__ == '__main__':
	nDoorms, mRooms = [int(i) for i in input().split()]
	roomList = [int(i) for i in input().split()]
	letterList = [int(i) for i in input().split()]
	total, idx = 0, 0
	for i in letterList:
		while total + roomList[idx] < i:
			total = total + roomList[idx]
			idx = idx + 1
		print(idx + 1, i - total)
