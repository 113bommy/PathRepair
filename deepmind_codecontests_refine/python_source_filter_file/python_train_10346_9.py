n,k=[int(x) for x in input().split(" ")]
c=[]
fi=[]
s=[]
v=[]
for _ in range(n):
	a,b= [int(y) for y in input().split(" ")]
	fi.append(a)
	c.append(b)
for i in c:
	if(i<=5):
		v.append(1)
	else:
		v.append(0)
for i in range(len(v)):
	if v[i]==1:
		s.append(fi[i])
	if(v[i]==0):
		g=fi[i]-(c[i]-k)
		#print(type(g))
		s.append(g)
s.sort()
q=(s[len(s)-1])
w=s.index(q)
print(s[w])



