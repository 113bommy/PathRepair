for _ in range(int(input())):
	n = int(input())
	a = input()
	if n%2==0:
		Rodd = 0
		for i in range(1,n,2):
			if int(a[i])%2==0:
				Rodd+=1
				break
		if Rodd==0:
			print(1)
		else:
			print(2)
	else:
		odd = 0
		for i in range(0,n,2):
			if int(a[i])%2==1:
				odd+=1
				break
		if odd==0:
			print(2)
		else:
			print(1)
