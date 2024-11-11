n=int(input())
a=[]
b=[]
for i in range(n):
	a1,p1=[int(x) for x in input().split()]
	a.append(a1)
	b.append(p1)
k=a[0]*b[0]
v=b[0]
for i in range(1,n):
	if b[i]<b[0]:
		v=b[i]
	k+=a[i]*v
print(k)
