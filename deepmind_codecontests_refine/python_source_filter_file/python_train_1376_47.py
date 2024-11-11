for i in range(int(input())):
	text= input()
	if text[-2:] == 'po':
		print("FILIPINO")
	elif text[-4:] == 'desu' or text[:-4] == 'masu':
		print("JAPANESE")
	elif text[-6:] == 'imnida':
		print("KOREAN")
