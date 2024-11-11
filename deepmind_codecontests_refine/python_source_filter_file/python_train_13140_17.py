t = int(input())
for i in range(t):
	n = int(input())
	arr = list(map(int, input().split()))
	sorted(arr)
	arr1 = arr[::-1]
	for j in range(len(arr1)):
		print(arr1[j], end=" ")
		print()