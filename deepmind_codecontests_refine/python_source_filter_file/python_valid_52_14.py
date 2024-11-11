def findAns(arr):
	arr.sort()
	res = -1e9 
	sums = 0
	tot = sum(arr)
	x = 0 
	n = len(arr)
	for i in range(len(arr)-1):
		sums+=arr[i]
		x+=1
		res = max(res,round(sums/x + (tot-sums)/(n-x),9))
	return res 

T = int(input())
for _ in range(T):
	n = int(input())
	arr = list(map(int,input().split()))
	print(findAns(arr))
