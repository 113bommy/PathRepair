n = int(input())

arr = list(map(int,input().split(" ")))

even = 0

for i in arr:

	if(i%2==0):
		even += 1


if(even == 0 or even == n):
	pass

else:
	arr.sort()
	print(*arr)