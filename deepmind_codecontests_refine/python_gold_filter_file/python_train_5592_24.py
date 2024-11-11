s = input()
index = s.find(".")
is_nine = s[index-1] == '9'

num_to_check = int(s[index+1])


if is_nine:
	print("GOTO Vasilisa.")
else:
	if num_to_check < 5:
		print(s[:index])
	else:
		print(int(s[:index])+1)