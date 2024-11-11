a,b=[int(x) for x in input().split()]
c,d=[int(x) for x in input().split()]
l=[]
for i in range(100):
	l.append(b+i*a)

flag=0
for i in range(100):
	if d+i*c in l:
		flag=1
		break
if flag==1:
	print(d+i*c)
else:
	print(-1)
