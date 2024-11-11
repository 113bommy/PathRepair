a=int(input())
n=[]
s=[]
sq=[]
for i in range(a):
	b=input()
	p1=b.find(' ')
	c=b[:p1]
	d=int(b[p1+1:])
	if c in n:
		i1=n.index(c)
		s[i1]+=d
		sq[i1].append([s[i1],i])
	else:
		n.append(c)
		s.append(d)
		sq.append([[d,i]])		
index=[z for z,x in enumerate(s) if x==max(s)]
top=max(s)
l=len(index)
min=1001
winner='abc'
print (sq,n,s)
for y in range(l):
	c=index[y]
	print(n[c],sq[c])
	l1=len(sq[c])
	for p in range(l1):
		a= sq[c][p][0]
		if a> top:
			if(int(sq[c][p][1])<min):
				min=int(sq[c][p][1])
				winner=n[c]
print(winner)




# index=[i for i,x in enumerate(a) if x==max(a)]