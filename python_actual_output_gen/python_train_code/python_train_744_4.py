n,k=map(int,input().split())
a=[i for i in map(int,input().split())]
b=[j for j in map(int,input().split())]
if k>1:
	print("Yes")
else:
	flag=True
	for i in range(n):
		if not a[i]:
			a[i]=b[0]

	for t in range(n):
		if(a[t]<a[t-1]):
			flag=False
			break

	if flag:
		print("No")
	else:
		print("Yes")