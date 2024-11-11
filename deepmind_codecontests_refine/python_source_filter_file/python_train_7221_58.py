for i in range(5):
	string=input().split()
	for j in range(5):
		if string[j]=="1":
			pos=(i,j)
			break
print(abs(pos[0]-3)+abs(pos[1]-3))