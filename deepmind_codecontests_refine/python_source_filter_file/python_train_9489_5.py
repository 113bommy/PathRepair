def find_half(arr):
	first_max = 1
	second_max = 1
	temp_max = 1

	for i in range(1,len(arr)//2): 
		if arr[i] >= arr[i-1]:
			temp_max+=1
		else:
			if temp_max > first_max:
				first_max = temp_max
				temp_max = 1
	if temp_max > first_max:
		first_max = temp_max

	temp_max = 1
	#print("first max: {}".format(first_max))

	for j in range(len(arr)//2+1,len(arr)):
		if arr[j] >= arr[j-1]:
			temp_max+=1
		else:
			if temp_max > second_max:
				second_max = temp_max
				temp_max = 1	

	if temp_max > second_max:
		second_max = temp_max	

	#print("second max: {}".format(second_max))

	if first_max+second_max == len(arr) and arr[len(arr)//2-1] <= arr[len(arr)//2]:
		#print("array sorted")
		return arr
	else:
		#print("array not sorted")
		if first_max > second_max:
			#print("first half is greater")
			return arr[:len(arr)//2]
		elif second_max > first_max:
			#print("second half is greater")
			return arr[len(arr)//2:]
		else: 
			#print("equal")
			return arr[:len(arr)//2]

		
def theranos_sort(arr):
	if len(arr) == 0:
		return None
	#print("first array: {}".format(arr))
	half = find_half(arr)
	#print("half array: {}".format(half))
	#print(len(half))
	#print(len(arr))
	if len(half) == len(arr):
		return len(half)
	if len(half) == 1:
		return 1
	else:
		return theranos_sort(half)

n = int(input())
arr = list(map(int, input().rstrip().split()))

print(theranos_sort(arr))