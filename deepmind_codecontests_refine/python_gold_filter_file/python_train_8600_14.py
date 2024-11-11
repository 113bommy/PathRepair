number = int(input())
for i in range(number):
	lst = []
	newLst = []
	count = 0
	num = int(input())
	if num != 1 and num != 2 and num != 3 and num != 5 and num != 7 and num != 11:
		if num%4 == 0:
			print(num//4)
		elif num%4 == 1:
			print((num-9)//4+1)
		elif num%4 == 2:
			print((num-6)//4+1)
		else:
			print((num-15)//4+2)
	else:
		print("-1")