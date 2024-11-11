n,a,b=map(int,input().split())
a1=list(map(int,input().split()))
b1=list(map(int,input().split()))
z=[i for i in range(1,n+1)]
c=[]
print(z)
for i in range(len(z)):
	if z[i] in a1:
		c.append(1)
	elif z[i] in b1:
		c.append(2)
for i in range(len(c)):
	print(c[i],end=" ")