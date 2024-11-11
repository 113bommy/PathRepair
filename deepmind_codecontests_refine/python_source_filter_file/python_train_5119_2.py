n,t = map(int,input().split())
x = list(map(int,input().split()))
ans=[]
for j1 in range(n):
	tem=[]
	for i1 in range(j1):
		tem.append(x[i1])
	tem.sort()
	# print(tem)
	m=0
	j=0
	c=0
	for i in range(j1):
		m+=tem[i]
		c+=1
		if(m>t-x[j1]):
			m-=x[j]
			j+=1
			c-=1
	ans.append(j1-c)

print(*ans)