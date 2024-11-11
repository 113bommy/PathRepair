t = input()
for i in range(int(t)):
	n = input()
	n = int(n)
	if(n % 2 == 0):
		for j in range(int(n / 2)):
			print("1", end="")
	else:
		print("7", end = "")
		for j in range(int((n - 3) / 2)):
			print("1", end="")
		print()
	
