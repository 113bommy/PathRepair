while True:
	try:
		number,weight,height=map(float,input().split(','))
		bmi=weight/(height)**2
		if bmi>=25:
			print(int(number))
	except EOFError:
		break