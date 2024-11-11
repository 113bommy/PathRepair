data = input()
if len(data) < 7:
	print('NO')
else:
	danger = False
	for i in range(len(data)-6):
		flag = True
		for j in range(1,7):
			if data[i] != data[i+j]:
				flag = False
				break 
		
		if flag:
			print('YES')
			danger = True
			break

	if not danger:
		print('NO')
