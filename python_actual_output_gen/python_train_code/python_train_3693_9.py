n = int(input())
for _ in range(len(str(n))):
	if n%10>5:
		print("-O|"+"O"*(n%10-5)+"-"+"O"*(9-n%10))
	else:
		print("O-|"+"O"*(n%10)+"-"+"O"*(4-n%10))
	n//=10