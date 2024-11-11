n = int(input())
arr = [None for i in range(n+1)]
num = 1
for i in range(2,n+1):
	if arr[i] == None:
		arr[i] = num
		j = i
		while i+i<=n:
			i+=i
			arr[i] = num
		num+=1
for i in range(2,n+1):
	print(arr[i],end=' ')
