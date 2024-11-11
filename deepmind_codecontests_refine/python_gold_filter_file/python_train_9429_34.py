def f():
	n=int(input())
	arr = [int(x) for x in input().split()]
	arr.sort()
	for i in range(2,n):
		if arr[i]<arr[i-1]+arr[i-2]:
			print("YES")
			return
	
	print("NO")
f()