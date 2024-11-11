i=input;i()
c=m=s=0
for i in i().split():
	i=int(i)
	c=c+1 if i>=s else 1
	m=max(m,c)
	s=i
print(m)