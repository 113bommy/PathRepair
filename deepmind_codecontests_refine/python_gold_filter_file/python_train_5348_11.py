a = list(input())
if a.count("0")==0:
	print("1"*(len(a)-1))
else:
	z = a.index("0")
	a.pop(z)
	print("".join(a))