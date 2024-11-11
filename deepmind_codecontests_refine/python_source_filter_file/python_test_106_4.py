t=int(input())
for _ in range(t):
	n=int(input())
	m=[]
	for i in range(3,n+3):
		m.append('1'*i)
	print(*m)