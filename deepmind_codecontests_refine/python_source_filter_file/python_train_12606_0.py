q=[int(i) for i in input().split()]
n=q[0]
m=q[1]
ar=[]
for i in range(0,n):
	x=[int(i) for i in input().split()]
	ar.append(x)
x1=0
x2=0
for i in ar:
	x1+=i[0]
	x2+=i[1]
if x1<=m:
	print(0)
	exit()
if x2>m:
	print(-1)
	exit()
if x2==m:
	print(n)
	exit()
ard=[]
ard1=[]
for i in ar:
	ard.append(i[0]-i[1])
ard1=[]
for i in range(0,len(ard)):
	ard1.append(ard[i])
ard1.sort()
ard1.reverse()
sum1=x1
ard2=[]
for i in ard:
	ard2.append(i)
c=0
for i in ard:
	sum1=sum1-i
	c+=1
	if sum1<=m:
		print(c)
		exit()