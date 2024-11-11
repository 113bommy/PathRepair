n = int(input())
arr = list(map(int, input().split()))
minm = 10**10
index = 0
for i in range(n):
	if(arr[i] < minm):
		minm = arr[i]
		index = i

flag = 1
for i in range(n):
	if(arr[i] == minm and i != index):
		print("Still Rozdil")
		flag = 0
		break

if(flag):
	print(index+1)