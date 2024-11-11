x,y,a,b = map(int,input().split())
l = []
if x <= b:
	print(0)
else:
	t = max(b+1,a)
	i = a 
	while i <= x:
		for j in range(b,i):
			l.append((i,j))
		i = i + 1
	print(len(l))
	for i in l:
		print(i[0],i[1])