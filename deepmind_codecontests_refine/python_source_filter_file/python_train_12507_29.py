a=int(input())
b=[]
for x in range(a):
	b.append(list(map(int,input().split())))
c=int(input())
for i in range(a):
	for j in range(b[i][0],b[i][1]+1):
		d=[]
		d.append(j)
		if c in d:
			print(i+1)