t=int(input())
for _ in  range(t):
	n=int(input())
	l=[]
	print(n-1)
	for i in range(n-1):
		l.append(n-i)
	print(*l)
