n = int(input()
arr = [[int(i) for i in list(input().split())] for j in range(n)]
for i in range(1,n):
	arr[i][0] += max(arr[i-1][1], arr[i-1][2])
	arr[i][2] += max(arr[i-1][1], arr[i-1][0])
	arr[i][1] += max(arr[i-1][0], arr[i-1][2])
print(max(arr[n-1]))