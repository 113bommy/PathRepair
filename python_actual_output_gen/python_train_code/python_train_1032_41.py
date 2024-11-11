x = input().split()
if x[2] == "week":
	if x[0] == "4" or x[0] == "5":
		print("52")
	else:
		print("51")
else:
	if x[0] == "31":
		print(7)
	elif x[0] == "30":
		print(11)
	else:
		print(12)