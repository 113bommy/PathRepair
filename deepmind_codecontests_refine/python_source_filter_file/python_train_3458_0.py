n,m=map(int,input().split())
mat= [ [int(x) for x in input().split()] for j in range(n)]
moves=0
for j in range(m):
	rotate=[0]*n
	rotations=0
	num_of_elements=0
	for i in range(n):
		if mat[i][j]<=(n-1)*m+j+1 and mat[i][j]>j and ((mat[i][j]-1-j)%m)==0:
			pos=(mat[i][j]-(j+1))//m
			rot=(i-pos+n)%n
			rotate[rot]+=1
	
	min_sub_moves=100001
	z=0
	for k in range(n):
		z= n-rotate[k]+k
		if z < min_sub_moves:
			min_sub_moves= z
	
	moves+= min_sub_moves
	
print(moves)
