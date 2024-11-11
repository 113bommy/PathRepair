length = int(input())
arr = (input().split())
for i in range(len(arr)):
	arr[i] = int(arr[i])

def isSorted(start,end):
	for i in range(start,end - 1):
		if arr[i] > arr[i+1]:
			return False
	return True

count = 0
flag = False
while True:
	iteration = int(length / (2 ** count))
	if iteration == 1:
		break
	for i in range(2 ** count):
		if isSorted(i * iteration, (i + 1) * iteration - 1):
			flag = True
			break
	if flag:
		break
	else:
		count += 1

print(iteration)



		


