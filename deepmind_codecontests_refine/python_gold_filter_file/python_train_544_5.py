for _ in range(int(input())):
	s = input()
	turn = 1
	while '10' in s or '01' in s:
		# print(s,turn)
		if '01' in s:
			s = s.replace('01','',1)
		else:
			s = s.replace('10','',1)
		turn = 1-turn
	
	if turn:
		print("NET")
	else:
		print("DA")