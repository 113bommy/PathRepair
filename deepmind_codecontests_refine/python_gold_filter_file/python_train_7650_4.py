n=int(input())
z=[]
t=[False for i in range(n+1)]
for i in range(1,n+1):
	k=0
	for j in range(1,i+1):
		if i%j==0:k+=1
	if k==2:t[i]=True
for i in range(1,n+1):
	if t[i]:
		k=1
		v=i
		while(v<=n):
			z+=[v]
			v*=i
print(len(z))
for i in range(len(z)):
	print(z[i],end=" ")
	