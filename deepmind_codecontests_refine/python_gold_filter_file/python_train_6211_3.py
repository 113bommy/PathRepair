t=int(input())
d={}
ans=[]
for t1 in range(0,t):
	s=input()
	l=list(s)
	i=1
	a=''
	b=''
	while(l[i]!='+'):
		a=a+l[i]
		i+=1;
	i+=1
	a=int(a)
	while(l[i]!=')'):
		b=b+l[i]
		i+=1

	b=int(b)
	i=i+2
	c=''
	while(i<len(l)):
		c=c+l[i]
		i+=1
	#print(a,b,c)
	c=int(c)

	x=(a+b)/c
	ans.append(x)
	if x not in d:
		d[x]=0
	d[x]+=1

for i in ans:
	print(d[i],end=' ')
print()
