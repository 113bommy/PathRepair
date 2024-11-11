n = int(input())
arr = list(map(int,input().split()))
if n==1:
	print(0)
elif n==2:
	if abs(arr[0]-arr[1])%2==0:
		print(2)
	else:
		print(1)
else:
	d = max(arr)
	for i in range(n-1):
		arr[n-1]-=d-arr[i]
	if (d+arr[n-1])%n==0:
		print(n)
	else:
		print(n-1)


