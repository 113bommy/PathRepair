a1=input().split()
a=list(a1)
k=0
c=-1
for i in range(int(a[0])):
	b1=input().split()
	b=list(b1)
	k+=(int(b[0])-c)%int(a[1])
	k+=int(b[1])-int(b[0])
#	print(k)
	c=int(b[0])
#	print(c)
print(k+1)
