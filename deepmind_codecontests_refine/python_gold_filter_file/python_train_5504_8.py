n = int(input())
for i in range(n):
	x = int(input())
	y = int(input())
	ans = x + y
	if(ans < 10**80):
		print(ans)
	else:
		print("overflow")
