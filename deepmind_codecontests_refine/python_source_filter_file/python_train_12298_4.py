n,p1,p2,p3,t1,t2=map(int,input().split())
l,x,l11=[],0,[]
for i in range(n):
	l1=list(map(int,input().split()))
	l.append(l1)
	x+=(l1[1]-l1[0])*p1
for i in range(1,n):
	y=l[i][0]-l[i-1][1]
	l11.append(y)
for i in range(n-1):
	if l11[i]>=t2:
		x+=(t1*p1)+((t2)*p2)+((l11[i]-t2-t1)*p3)
	elif l11[i]>=t1:
		x+=(t1*p1)+((l11[i]-t1)*p2)
	else:
		x+=(l11[i])*p1
print(x)