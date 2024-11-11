n, k = map(int, input().strip().split())
arr = list(map(int, input().strip().split()))
currSum = sum(arr[:k])
ans = currSum
ind = 0
for i in range(k, len(arr)):
	currSum -= arr[i-k]
	currSum += arr[i]
	if currSum < ans:
		ind = i-1
		ans = currSum
print(ind)
	