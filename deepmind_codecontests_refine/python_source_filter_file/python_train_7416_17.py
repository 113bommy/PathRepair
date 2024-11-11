import bisect
mx=-10**9
t=int(input())
p=[]
for i in range(t):
	n=int(input())
	c=0
	p.append(n)
mx=max(p)
#print(mx)
l=[2,7,15]
while True:
	x=l[-1]-l[-2]+3
	pp=x+l[-1]
	print(pp)
	if pp>mx:
		break
	l.append(pp)
	##print(l)
#print(l)

for i in range(t):
	n=p[i]
	c=0
	while n>1:
		j=bisect.bisect_left(l,n)
		#print(j)
		if j<len(l):
			if l[j]==n:
				n-=n
				c+=1
				continue
		if j>0:
			n-=l[j-1]
			c+=1
	print(c)
		