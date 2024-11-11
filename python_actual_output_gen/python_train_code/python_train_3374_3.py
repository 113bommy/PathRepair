for _ in range(int(input())):
	a = input().split()
	a1 = int(a[0])
	a2 = int(a[1])
	a3 = int(a[2])
	result = abs(a1-a2)+abs(a2-a3)+abs(a1-a3)
	if(result==0):
		print("0")
	elif(result<4):
		print(result)
	else:
		print(result-4)




