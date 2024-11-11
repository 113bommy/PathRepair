A, B, C = 0, 0, 0

for i in range(3):
	val = input()
	if val[1] == "<":
		val = val[2] + ">" + val[0]
	if val[0] == "A" and val[2] == "B":
		B += 1
		A += 2
	elif val[0] == "B" and val[2] == "A":
		B += 2
		A += 1
	elif val[0] == "B" and val[2] == "C":
		B += 2
		C += 1
	elif val[0] == "C" and val[2] == "B":
		C += 2
		B += 1
	elif val[0] == "A" and val[2] == "C":
		A += 2
		C += 1
	elif val[0] == "C" and val[2] == "A":
		C += 2
		A += 1
	else:
		print("Bla Bla...")
if A > B > C: print("CBA")
elif A > C > B: print("BCA")
elif B > A > C: print("CAB")
elif B > C > A: print("ACB")
elif C > A > B: print("BAC")
elif C > B > A: print("ABC")
else: print("Impossible")
