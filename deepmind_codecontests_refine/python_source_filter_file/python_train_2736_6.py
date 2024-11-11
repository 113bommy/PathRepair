def ans(i,j):
	x=i+1 if i<n else i-1
	y=j+1 if j<m else j-1
	print(i,j,i,y,x,y)
	print(i,y,x,j,x,y)
	print(i,j,i,y,x,j)

for _ in range(int(input())):
	n,m=map(int,input().split())
	l=[list(map(int,list(input()))) for i in range(n)]
	print(sum(sum(z) for z in l)*3)
	for i in range(n):
		for j in range(m):
			if l[i][j]==1:
				ans(i+1,j+1)