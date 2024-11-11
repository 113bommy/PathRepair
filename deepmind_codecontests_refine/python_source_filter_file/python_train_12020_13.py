x,y,m,n= map(int,input().strip().split())
a=x*n
if x%y==0:
	b=(x//y)*m
	c=x*y*m
else:
	b=(x//y+1)*m
	c=x//y*m+(x%y*n)
menor=a
if b<menor:
	menor=b
if c<menor:
	menor=c
print(menor)