t = input()
i = 1

while i <= len(t):
	if int(t[-i]) <= 5:
		print("O-|"+"O"*int(t[-i])+"-"+"O"*(4-int(t[-1])))
	elif int(t[-i]) <= 9:
		print("-O|"+"O"*int(t[-i]-5)+"-"+"O"*(9-int(t[-i])))
	i = i + 1
