n=int(input())
a=list(map(int,input().split()))
m=int(1e6)
b=[-1]*n
e=0
v=[0]*m
for i in range(n):
	if a[i]!=e:
		b[i]=e
		v[e]=1
		e=a[i]
		v[e]=1
k=0
for i in range(n):
	while v[k]==1:
		k+=1
	if(b[i]==-1):
		b[i]=k
		v[k]=1
print(*b)




