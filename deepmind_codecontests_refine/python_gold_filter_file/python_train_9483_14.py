n,m=map(int,input().split())
n1=list(map(int,input().split()))
m1=list(map(int,input().split()))
c=0
f=m1[0]
k=0
for i in range(n):
	if(k==(m-1)):
		if(f>=n1[i]):
			c=c+1
			break
	if(f>=n1[i]):
		k=k+1
		f=m1[k]
		c=c+1
	
print(c)