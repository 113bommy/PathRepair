t = input()
if t[0] == "a" and (t[1] == "0" or t[1] == "8")\
and t[0] == "h" and (t[1] == "0" or t[1] == "8"):
	print("3")
elif t[0] == "a" or t[0] == "h" or t[1] == "0"\
or t[1] == "8":
	print("5")
else:
	print("8")