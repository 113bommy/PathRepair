i=input;
c=m=s=0
for i in input().split():
	i=int(i)
	c=c+1 if i>=s else 1
	m=max(m,c)
	s=i
print(m)