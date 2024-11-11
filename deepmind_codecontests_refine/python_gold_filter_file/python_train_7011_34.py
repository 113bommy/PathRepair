n,m=map(int,input().split(" "))
k=0
if(n>m):
	max=n
	min=m
else:
	max=m
	min=n
c=0
for i in range(max+1):
	s=pow(n-i,0.5)+(i*i)
	if(s==m):
		c=c+1
print(c)