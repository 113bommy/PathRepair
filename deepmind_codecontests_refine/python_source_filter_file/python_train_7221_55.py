matrix=[]
for i in range(5):
	matrix.append(input())
row,col=0,0
for i in range(4):
	if matrix[i].find("1")!=-1:
		col=matrix[i].find("1")//2
		row=i
print("%d"%(abs(row-2)+abs(col-2)))
