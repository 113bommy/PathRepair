while True:
	try:
		x,y=input().split()
		print(x+y)
	except EOFError:
		break