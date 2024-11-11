for _ in range(int(input())):
	(n,m) = list(map(int,input().split()))
	mat = []
	for i in range(n):
		mat.append(list(map(int,input().split())))
	row =[]
	col =[]
	for i in range(len(mat)):
		for j in range(len(mat[i])):
			if mat[i][j]==1:
				row.append(i+1)
				col.append(j+1)
	count = 0
	for i in range(n):
		for j in range(m):
			if i+1 not in row and j+1 not in col:
				count += 1
	vr = n + m -1
	i = 0 
	r = len(list(set(row)))
	c = len(list(set(col)))
	while count>0:
		count = count- vr -r-c
		i+=1
		r+=1
		c+=1
	if i%2==0:
		print("Vivek")
	else:
		print("Ashish") 




