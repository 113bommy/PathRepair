n,m,k=map(int,input().split())
a=list(map(int,input().split()))
x=a.count(1)
y=a.count(2)
c=0
if x>m:
	c+=(x-m)
	m=0	
else:
	m-=x
if y>k+m:
	c+=(y-k-m)
print(c)