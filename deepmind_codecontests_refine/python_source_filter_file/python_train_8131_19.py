import bisect
n, k = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort()

total = 0
for _ in range(k):
	i = bisect.bisect_left(arr, total + 1)
	
	if(i >= n): 
		print(0)
		continue
	print(arr[i] - total)
	total += arr[i]