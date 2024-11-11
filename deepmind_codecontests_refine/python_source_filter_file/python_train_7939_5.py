def check(arr):
	n = len(arr)
	ans = 0
	for i in range(1,n-1):
		if arr[i]<arr[i-1] and arr[i]<arr[i+1]:
			ans+=1
	return ans
n = int(input())
a = list(map(int,input().split()))
arr = [None]*n
a.sort()
start = 0
for i in range(1,n-1,2):
	arr[i] = a[start]
	start+=1
for i in range(n):
	if arr[i]==None:
		arr[i] = a[start]
		start+=1
print(check(arr))
print(*arr)