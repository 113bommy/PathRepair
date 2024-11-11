entrada = int(input())
if entrada <= 3:
	print("NO")

elif entrada%2 == 0:
	print("YES")
	print("1 * 2 = 2")
	print("2 * 3 = 6")
	print("6 * 4 = 24")
	for i in range(5,entrada,2):
		print (str(i+1)+" + "+str(i)+" = 1")
		print("24 * 1 = 24")

else:
	print("YES")
	print("2 - 1 = 1")
	print("1 + 3 = 4")
	print("4 * 5 = 20")
	print("20 + 4 = 24")
	for j in range(6,entrada,2):
		print (str(j+1)+" + "+str(j)+" = 1")
		print("24 * 1 = 24")