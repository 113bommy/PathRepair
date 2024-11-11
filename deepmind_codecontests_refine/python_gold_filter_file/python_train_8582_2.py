l_6 = ["espeon"]
l_7 = ["jolteon", "flareon", "umbreon", "leafeon", "glaceon", "sylveon"]
l_8 = ["vaporeon"]

input_length = input()
input_string = input()

if input_length == "6":
	print(l_6[0])
elif input_length == "8":
	print(l_8[0])
else:
	for x in l_7:
		for y in range(0,7):
			if(input_string[y] != '.' and input_string[y] != x[y]):
				break
			if (y == 6):
				print(x)