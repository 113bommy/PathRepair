n,m=map(int,input().split(" "))
y=0
for i in range(n):
	l=list(map(int,input().split(" ")))
	for j in range(m):
		x=l[(j*m):(j*m)+m]
		if 1 in x:
			y+=1
print(y)