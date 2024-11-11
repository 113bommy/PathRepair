for _ in range(int(input())):
	n = int(input())
	i = 2
	div = 3
	while i<5:
		if n/div == n//div:
			print(n//div)
			break 
		div += (2**i)
		i += 1
		#print(div)
		
#1 2 4 8 16 32
