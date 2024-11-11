X = int(input())

for a in range(-118,119,1):
	for b in range(-119,118,1):
		if a**5 - b**5 == X:
			print(a,b)
			exit()