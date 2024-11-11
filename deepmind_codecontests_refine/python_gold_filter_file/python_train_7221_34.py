
l=[]
for i in range(5):
	l.append(list(map(int,input().split())))
for i in range(5):
	for j in range(5):
		if(l[i][j]==1):
			print(abs(2-i)+abs(2-j))
