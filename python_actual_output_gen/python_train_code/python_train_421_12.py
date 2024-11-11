n = int(input())
array = list(map(int, input().split()))

l = 0
r = n - 1
sortedArray = sorted(array)

if (array == sorted(array)):
	print("yes")
	print('1 1')
else:
	for i in range(0,len(array)):
		if array[i] != sortedArray[i]:
			l = i
			break

	for i in range(len(array)-1,-1,-1):
		if array[i] != sortedArray[i]:
			r = i
			break


	check = True
	for i in range(l, r):
		if not array[l] > array[l+1]:
			check = False
			break

	if check:
		print("yes")
		print("{0} {1}".format(l+1, r+1))
	else:
		print("no")


		