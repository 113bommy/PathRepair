if __name__ == '__main__':
	n = int(input())
	arr = [int(i) for i in input().split()]
	
	for i in range(n - 1, -1, -1):
		for j in range(0, i):
			if(arr[j] > arr[j + 1]):
				arr[j], arr[j + 1] = arr[j + 1], arr[j]
				print(j + 1, j + 2)
	#print(arr)

