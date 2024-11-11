n,m=map(int,input().split())
sum_s=0
r=[]
c=0
e=0
for i in range(n):
	a,b=map(int,input().split())
	sum_s=sum_s+a
	subs=a-b
	r.append(subs)
	e=e+b
y=sum_s
r.sort()
r.reverse()
j=0
if(e<m):
	while(y>m and j<n):
		y=y-r[j]
		j=j+1
		c=c+1
	print(c)
else:
	print("-1")

	