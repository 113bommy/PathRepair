t=1


for _ in range(t):
	n,m=map(int,input().split())
	l=list(map(int,input().split()))
	f=True
	an=[]
	for i in range(m):
		if l[i]>n-i:
			f=False
			break
	if not f or sum(l)<n:
		print(-1)
		continue
	c=sum(l)-n
	an=[1]
	for i in range(1,m):
		if c>0:
			d=min(c,l[i-1]-1)
			an.append(an[-1]+l[i-1]-d)
			c-=d
		else:
			an.append(an[-1]+l[-1])
	if c>0:print(-1)
	else:print(*an)

