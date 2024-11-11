n,m,k=map(int,input().split())
a=list(map(int,input().split()))
x=a.count(1)
y=a.count(2)
c=0
if x>m:
	c+=(x-m)
	x-=m	
else:
	x-=m
if y+x>k+m:
	c+=(y+x-k-m)
print(c)