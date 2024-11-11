n,h,m=map(int,input().split())
a=[h]*n
c=0
for i in range(m):
	l,r,x=map(int,input().split())
	for j in range(l-1,r):
		a[j]=min(h,x,a[j])
# print(a)		
for i in a:
	c+=(i*i)
print(c)