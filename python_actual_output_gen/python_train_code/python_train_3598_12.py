l=[]
c=[]
a=0

for i in range(96,123):
	l.append(i)
for i in list(input()):
	c.append(l.index(ord(i)))
a=min(abs(1-c[0]),abs(26-1-c[0]))
for i in range(1,len(c)):
	a=min(abs(c[i-1]-c[i]),abs(26-abs(c[i-1]-c[i])))+a
print(a)