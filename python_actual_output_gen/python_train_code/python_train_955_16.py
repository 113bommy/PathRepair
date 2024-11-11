for _ in range(int(input())):
	n = int(input())
	arr = [int(i) for i in input().split()]
	f = 0
	for i in range(1,n):
		if(abs(arr[i-1]-arr[i])>=2):
			print("YES")
			print(i-1,i)
			f = 1
			break
	if f==0:
		print("NO")