t=int(input())
for _ in  range(t):
	n=int(input())
	l=[]
	print(n)
	for i in range(n):
		l.append(i+1)
	print(*l)
