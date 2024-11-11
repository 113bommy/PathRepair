I=lambda:list(map(int,input().split()))
n,m=I()
a=[0]*n
b=[0]*m
for i in I()[1:]:a[i]=1
for i in I()[1:]:b[i]=1
y=1
l=r=0
while y:
	y=0;l,r=r,l+200
	for i in range(l,r):
		if a[i%n]^b[i%m]:y=1
		a[i%n]=b[i%m]=a[i%n] or b[i%m]
print(['NO','YES'][all(a+b)])