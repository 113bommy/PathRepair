l=[]
for i in range(5):
	l.append(list(map(int,input().split())))
for i in range(5):
	for j in range(5):
		if(l[i][j]==1):
			print(abs(3-i)+abs(3-j))

