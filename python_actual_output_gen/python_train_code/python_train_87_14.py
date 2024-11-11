for i in range(int(input())):
	a = int(input())
	b = 0
	while True:
		if a == 1:
			print(a)
			break
		if a % 6 == 0:
			a/=6
		else:
			if a % 3 == 0:
				a*=2
			else:
				print(-1)
				break
		b+=1