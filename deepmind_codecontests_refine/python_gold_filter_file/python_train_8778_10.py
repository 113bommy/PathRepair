n,m=map(int,input().split())
l=[]
for _ in range(m):
	k1,m1=map(int,input().split())
	l.append([m1,k1])
l.sort()
s,box=0,0

for x in range(m-1,-1,-1):
	m,k=l[x]
	box+=k
	if box>n:
		s+=m*(k-(box-n))
		print(s)
		break
	elif box==n:
		s+=m*k
		print(s)
		break
	else:
		s+=m*k
else:print(s)