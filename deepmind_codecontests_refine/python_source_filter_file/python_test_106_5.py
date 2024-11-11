t=int(input())
for _ in range(t):
	n=int(input())
	m=[]
	for i in range(1,n+1):
		m.append('1'*i)
	print(*m)