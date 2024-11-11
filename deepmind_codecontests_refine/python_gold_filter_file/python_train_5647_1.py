t=int(input())

for _ in range(t):
	n,m=map(int,input().split())

	str1='B'	
	M=[[str1]*m for i in range(n)]
	
	for i in range(n):
		for j in range(m):
			if i+j==0:
				M[i][j]='W'

	#M[0][0]='W'
	for row in M:
		print(''.join([str(elem) for elem in row]))

