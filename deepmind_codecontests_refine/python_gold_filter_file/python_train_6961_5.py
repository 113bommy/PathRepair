while True:
	try:
		x=[[int(i) for i in input()] for j in range(8)]
		count=0
		num=[]
		for i in range(8):
			if x[i].count(1)!=0:
				num.append(i)
				count+=1
		if count==1:
			print("C")
		elif count==4:
			print("B")
		elif count==2:
			for j in range(8):
				if x[num[0]][j]==1:
					if j==0:
						if x[num[0]+1][j]==1:
							print("A")
						else:
							print("E")
					else:
						if x[num[0]+1][j-1]==1:
							print("G")
						else:
							if x[num[0]+1][j]==1:
								print("A")
							else:
								print("E")
					break
		else:
			for j in range(8):
				if x[num[0]][j]==1:
					if j==0:
						print("F")
					else:
						if x[num[0]+1][j-1]==1:
							print("D")
						else:
							print("F")
					break
		input()
	except EOFError:
		break
