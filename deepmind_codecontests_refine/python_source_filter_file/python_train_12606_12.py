n,m=map(int,input().strip().split())
a=[]
b=[]
diff=[]
for i in range(n):
	r,s=map(int,input().strip().split())
	a.append(r)
	b.append(s)
	diff.append(r-s)
d=sum(a)
e=sum(b)
if (d<=m):
	print (0)
	exit(0)
if (e>m):
	print (0)
	exit(0)
p=d-m
diff.sort()
for i in range(n-1,-1,-1):
	p=p-diff[i]
	if p<=0:
		print (n-i)
		exit(0)

