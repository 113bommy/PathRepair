n = int(input())
c = n**0.5
if c%1==0:
	print(int(c), int(c))
else:
	for i in range(int(c), 1, -1):
		if n%i==0:
			print(i, n//i)
			exit()