import math
t = int(input())


for _ in range(t):
	n = int(input())
	arr = list(map(int,input().strip().split()))
	ans = 0
	for i in range(1,n):
		if arr[i] < arr[i-1]:
			ans = max(ans, math.ceil(math.log(arr[i-1] - arr[i], 2))+1)
			arr[i] = arr[i-1]
	print(ans)