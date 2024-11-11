n=int(input())
arr=list(map(int,input().split()))
if n<=1:
	print("-1")
else:
	if n==2:
		if arr[0]==arr[1]:
			print("-1")
		else:
			print(1)
			print(1)
	else:
		a=sorted(arr)
		if a[0]==a[n-1]:
			print((n//2)+1)
			for i in range(n//2+1):
				print(i+1,end=" ")
			print()
		else:
			print("1")
			print(arr.index(a[0]))

