n = int(input())
if(n == 1 or n == 2):
	print(1)
	print(1)
elif(n==3):
	print(2)
	print(1,3)
elif(n==4):
	print(3)
	print(3,1,4,2)
else:
	k = 1
	print(n)
	for x in range(n):
		print(k, end=' ')
		k += 2
		if(k > n):
			k = 2
	