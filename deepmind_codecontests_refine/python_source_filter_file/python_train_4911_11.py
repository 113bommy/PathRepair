n = int(input())
spaces = 2*n-2
buff = None
for i in range(2*n+1):
	if(i <= n):
		print(" "*spaces, end = "")
	if(i == 0):
		print("  "+str(0), end = "")
		print()
		continue
	elif(i > n):
		if(buff == None):
			buff = n
		if(spaces < 0):
			spaces = 0
		spaces+=2
		print(" "*(spaces), end = "")
		if(i == 2*n):
			print(str(0), end = "")
			continue
		buff -= 1
		for j in range(buff+1):
			print(j, end = " ")
		for j in range(buff-1, -1, -1):
			print(j, end = " ") 
		print()
		continue
	else:
		for j in range(i+1):
			print(j, end = " ")
		for j in range(i-1, -1, -1):
			print(j, end = " ")
	spaces -= 2
	print()
