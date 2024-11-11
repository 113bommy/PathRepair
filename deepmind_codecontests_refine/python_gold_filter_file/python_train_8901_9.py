a,b=map(int,input().split())
count=0
d={
	0:6,
	1:2,
	2:5,
	3:5,
	4:4,
	5:5,
	6:6,
	7:3,
	8:7,
	9:6
}
for i in range(a,b+1):
	l=0
	k=str(i)
	for j in k:
		count+=d[int(j)]
print(count)