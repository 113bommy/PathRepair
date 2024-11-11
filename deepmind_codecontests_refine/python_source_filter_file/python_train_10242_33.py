def adjacent_index(i,j):
	index=[]

	if i>0:
		index.append((i-1,j))
	if i+1<3:
		index.append((i+1,j))
	if j>0:

		index.append((i,j-1))
	if j+1<3:
		index.append((i,j+1))

	return index

a=[[1 for i in range(3)] for i in range(3)]

for i in range(3):

	element=list(map(int,input().split()))

	for j in range(3):
		a[i][j]=element[j]

res=[[1 for i in range(3)] for j in range(3)]

for i in range(3):

	for j in range(3):

		if a[i][j]!=0 and a[i][j]%2!=0:

			if res[i][j]==0:
				res[i][j]=1
			else:
				res[i][j]=0


			index=adjacent_index(i,j)

			for k in index:

				if res[k[0]][k[1]]==1:
					res[k[0]][k[1]]=0
				else:
					res[k[0]][k[1]]=1






for i in range(3):

	for j in range(3):

		print(res[i][j],end=" ")

	print()



