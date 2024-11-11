t=int(input())
for i in range(t):
	n=int(input())
	m=4*n-2
	for j in range(n):
		print(m,end=" ")
		m=m-n
	print()
		