if __name__ == '__main__':
	n,k = tuple(map(int,input().strip(" ").split(" ")))
	arr = list(map(int,input().strip(" ").split(" ")))
	teams = set()
	for i in range(len(arr)):
		if 5-arr[i] > k:
			teams.add(i)
	print(len(teams)//3)
