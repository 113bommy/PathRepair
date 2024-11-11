n,m = [int(i) for i in input().split()]
A=[]
b=[]
for i in range(m):
	A.append([int(j) for j in inpur().split()])
for i in range(m):
	b.append(int(input()))
for i in range(n):
	s = 0
	for j in range(m):
		s+=A[i][j]*b[j]
	print(s)