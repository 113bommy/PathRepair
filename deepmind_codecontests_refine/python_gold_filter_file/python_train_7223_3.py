for x in range(int(input())):
	a = input()
	b = len(a) - 5
	print
	if "lala." in a[b:] and "miao." in a[:5]:
		print("OMG>.< I don't know!")
	elif "miao." in a[:5]:
		print("Rainbow's")
	elif "lala." in a[b:]:
		print("Freda's")
	else:
		print("OMG>.< I don't know!")