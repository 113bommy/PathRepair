x=int(input());a=input();b='x'*x;c=list(b)
for i in range(x):
	c[b.find('x',(len(a)-1)//2)]=a[0]
	b=''.join(c)
	a=a.replace(a[0],'',1)
print(b)
#author:SK__Shanto__㋛
#code__define__your__smartness