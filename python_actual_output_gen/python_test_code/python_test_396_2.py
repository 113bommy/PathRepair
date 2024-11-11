while True:
	try:
		value = input().split(" ")
		result = int(value[0]) * int(value[1])
		print(str(result))
	except EOFError:
		break