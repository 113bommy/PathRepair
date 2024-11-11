L=[]
for i in range(0,5):
	s=str(input())
	L.append(list(map(int,s.split())))
#print(L)
for i in range(0,5):
	for j in range(0,5):
		if(L[i][j]==1):
			print(abs(i-2)+abs(j-2))
			

