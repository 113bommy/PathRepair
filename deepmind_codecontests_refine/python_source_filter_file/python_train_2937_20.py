r,c=list(map(int,input().split()))
gcds=[i for i in range(1,r+c+1)]
arr=[]
if r==1 and c==1:
	print(0)
if r==1:
	print(*[i+2 for i in range(c)])
	exit()
elif c==1:
	for i in range(r):
		print(i+2)
	exit()
for _ in range(r):
	arr.append([0]*c)
row=[]
col=[]
for i in range(r):
	row.append(gcds[i])
for i in range(c):
	col.append(gcds[r+c-1-i])
for i in range(r):
	for j in range(c):
		arr[i][j]=row[i]*col[j]
for i in arr:
	print(*i)
