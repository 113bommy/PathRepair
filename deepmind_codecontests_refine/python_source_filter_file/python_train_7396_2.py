while True:
	a,b,c = input().split()

	if b == "?":
		break
	elif b == "+":
		s = int(a)+int(c)
	elif b == "-":
		s = int(a)-int(c)
		
	elif b == "*":
		s = int(a)*int(c)
		
	else :
		s = int(a)/int(c)
	print(s)