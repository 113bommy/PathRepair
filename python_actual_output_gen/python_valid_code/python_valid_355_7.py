N = int(input())
for i in range(N):
	n = int(input())
	array = input().split()
	for j in range(n):
		array[j]=int(array[j])
	array.sort
	for j in range(n-1,-1,-1):
		print(array[j], end=' ')
	print()