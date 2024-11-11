while True:
	try:
		print(sum([eval(x) for x in input().split()]))
	except EOFError:
		break