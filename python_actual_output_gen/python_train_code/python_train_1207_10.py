n,m=map(int,input().split())
a=list(input())
for i in range(m):
	l1=list(input().split())
	c1,c2,l,r=l1[2],l1[3],int(l1[0]),int(l1[1])
	for j in range(l-1,r):
		if a[j]==c1:
			a[j]=c2
	print(*a,sep='')